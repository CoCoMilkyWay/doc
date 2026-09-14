# Copyright (c) Opendatalab. All rights reserved.
import os

from loguru import logger

from .pdf_image_tools import cut_image


def cut_image_and_table(span, page_pil_img, page_img_md5, page_id, image_writer, scale=2):

    def return_path(path_type):
        return f"{path_type}/{page_img_md5}"

    span_type = span["type"]

    if not check_img_bbox(span["bbox"]) or not image_writer:
        span["image_path"] = ""
    elif span_type in ("image", "chart") and _too_small(span["bbox"]):
        # docpipe 剪裁: 研报里 PDF 点坐标下短边不足 DOCPIPE_IMG_MIN_SIDE_PT 的"图"都是电话/邮箱/logo 图标,
        # 不落盘也不进 md (image_path 为空时 md 渲染直接跳过). 公式/表格截图不过滤 (公式本就小)
        span["image_path"] = ""
    else:
        span["image_path"] = cut_image(
            span["bbox"], page_id, page_pil_img, return_path=return_path(span_type), image_writer=image_writer, scale=scale
        )

    return span


def _too_small(bbox) -> bool:
    min_side = float(os.environ["DOCPIPE_IMG_MIN_SIDE_PT"])
    assert min_side >= 0, min_side
    return min(bbox[2] - bbox[0], bbox[3] - bbox[1]) < min_side


def check_img_bbox(bbox) -> bool:
    if any([bbox[0] >= bbox[2], bbox[1] >= bbox[3]]):
        logger.warning(f"image_bboxes: 错误的box, {bbox}")
        return False
    return True
