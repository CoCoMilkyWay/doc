# Barra China Equity Model (CNE5)

Descriptor Details

September 2013

The ten style factors of CNE5 comprise a total of 21 descriptors. This document defines these descriptors and their weights in the style factors. The descriptors are listed under the style factors to which they belong.

Style: Beta

Definition: 1.00 BETA

Components: BETA Beta (β) Computed as the slope coefficient in a time-series regression of excess stock return, $\boldsymbol{r}_{t}-\boldsymbol{r}_{ft}$ , against the cap-weighted excess return of the estimation universe $\scriptstyle{R_{t}},$

$$
\boldsymbol{r}_{t}-\boldsymbol{r}_{ft}=\boldsymbol{\alpha}+\beta\boldsymbol{R}_{t}+\boldsymbol{e}_{t}\tag{1}
$$

The regression coefficients are estimated over the trailing 252 trading days of returns with a half-life of 63 trading days.

Style: Momentum

Definition: 1.00 RSTR

Components: RSTR Relative strength Computed as the sum of excess log returns over the trailing T= 504 trading days with a lag of L = 21 trading days,

$$
\begin{array}{r}{RSTR=\sum_{t=L}^{T+L}w_{t}\big[ln(1+r_{t})-ln\big(1+r_{ft}\big)\big]\mathrm{~,~}}\end{array}\tag{2}
$$

where, $\boldsymbol{r}_{t}$ is the stock return on day $t,r_{ft}$ is the risk-free return, and ${\bf{\boldsymbol{w}}}_{t}$ is an exponential weight with a half-life of 126 trading days.

Style: Size

Definition: 1.00 LNCAP

Components: LNCAP Natural log of market cap Computed by the logarithm of the total market capitalization of the firm.

Style: Earnings Yield

Definition: 0.68 · EPIBS + 0.11 · ETOP + 0.21 · CETOP

Components: EPIBS Analyst Predicted Earnings-to-Price Earnings-to-price ratio forecasted by analysts.

ETOP Trailing earnings-to-price ratio Computed by dividing the trailing 12-month earnings by the current market capitalization. Trailing earnings are defined as the last reported fiscal-year earnings plus the difference between current interim figure and the comparative interim figure from the previous year.

CETOP Cash earnings-to-price ratio Computed by dividing the trailing 12-month cash earnings divided by current price.

Style: Residual Volatility

Definition: 0.74· DASTD + 0.16 · CMRA + 0.10 · HSIGMA

Components: DASTD Daily standard deviation Computed as the volatility of daily excess returns over the past 252 trading days with a half-life of 42 trading days.

CMRA Cumulative range

This descriptor differentiates stocks that have experienced wide swings over the last 12 months from those that have traded within a narrow range. Let Z(T) be the cumulative excess log return over the past Tmonths, with each month defined as the previous 21 trading days,

$$
\begin{array}{r}{Z(T)=\sum_{\tau=1}^{T}\bigl[ln(1+r_{\tau})-ln\bigl(1+r_{f\tau}\bigr)\bigr],}\end{array}\tag{3}
$$

where, $r_{\tau}$ is the stock return for month τ (compounded over 21 days) and $r_{f\tau}$ is the risk-free return. The cumulative range is given by,

$$
CMRA=Z_{max}-Z_{min},\tag{4}
$$

where, $\begin{array}{l}{{Z_{max}=max\{Z(T)\},}}\\{{Z_{min}=min\{Z(T)\}}}\\{{T=\mathcal{I},...,\mathcal{I}\mathcal{Z}}}\end{array}$

HSIGMA Historical sigma (σ) Computed as the volatility of residual returns in Equation 1,

$$
\pmb{\sigma}=st\pmb{d}(\pmb{e}_{t}).\tag{5}
$$

The volatility is estimated over the trailing 252 trading days of returns with a half-life of 63 trading days.

Note: The Residual Volatility factor is orthogonalized to Beta to reduce collinearity.

Style: Growth

Definition: 0.47 · SGRO + 0.24 · EGRO +0.18 · EGIBS + 0.11 · EGIBS_s

Components: SGRO Sales growth (trailing five years) Annual reported sales per share are regressed against time over the past five fiscal years. The slope coefficient is then divided by the average annual sales per share to obtain the sales growth.

EGRO Earnings growth (trailing five years) Annual reported earnings per share are regressed against time over the past five fiscal years. The slope coefficient is then divided by the average annual earnings per share to obtain the earnings growth.

EGIBS Long-term Predicted Earnings Growth Long-term earnings growth forecasted by analysts.

EGIBS_s Short-term Predicted Earnings Growth Short-term earnings growth forecasted by analysts.

Style: Book-to-Price

Definition: 1.00 · BTOP

Components: BTOP Book-to-Price Last reported book value of common equity divided by current market capitalization.

Style: Leverage

Definition: 0.38 · MLEV + 0.35 · DTOA + 0.27 · BLEV

$$
\begin{array}{r}{MLEV=\frac{ME+PE+LD}{ME},}\end{array}\tag{6}
$$

where, ME is the market value of common equity on the last trading day, PE is the most recent book value of preferred equity, and LD is the most recent book value of long-term debt.

$$
DTOA={\frac{TD}{TA}},\tag{7}
$$

where, TD is the book value of total debt (long-term debt and current liabilities) and TA is most recent book value of total assets.

BLEV Book leverage Computed as $\begin{array}{r}{BLEV=\frac{BE+PE+LD}{BE},}\end{array}$

(8)

where, BE is the most recent book value of common equity, PE is the most recent book value of preferred equity, and LD is the most recent book value of long-term debt.

Style: Liquidity

Definition: 0.35 · STOM + 0.35 · STOQ + 0.30 · STOA

Components: STOM

Computed as the log of the sum of daily turnover during the previous 21 trading days,

$$
\begin{array}{r}{STOM=\mathbf{ln}\left(\sum_{t=1}^{21}\frac{V_{t}}{S_{t}}\right),}\end{array}\tag{9}
$$

where, is $\pmb{V}_{t}$ the trading volume on day t and $\pmb{S}_{t}$ is the number of shares outstanding.

STOQ Average share turnover, trailing 3 months Let $STOM_{\tau}$ be the share turnover for month τ, with each month consisting of 21 trading days. The quarterly share turnover is defined by, $\begin{array}{r}{{STOQ}=\ln{\left(\frac{1}{T}\sum_{\tau=1}^{T}\exp{(STOM_{\tau})}\right)},}\end{array}$ (10) where, T = 3 months.

STOA Average share turnover, trailing 12 months Let STOM be the share turnover for month τ, with each month consisting of 21 trading days. The annual share turnover is defined by, $\begin{array}{r}{{STOA}=\mathbf{ln}~\Big(\frac{1}{T}\sum_{\tau=1}^{T}\mathbf{exp}~({STOM_{\tau}})\Big),}\end{array}$ (11) where, T = 12 months.

Style: Non-linear Size

Definition: 1.00 · NLSIZE

Components: NLSIZE Cube of Size First, the standardized Size exposure (i.e., log of market cap) is cubed. The resulting factor is then orthogonalized to the Size factor on a regressionweighted basis. Finally, the factor is winsorized and standardized.

## Global Client Service Assistance is Available 24 Hours a Day

## clientservice@msci.com

## Americas

| Americas | 1.888.588.4567 (toll free) |
| --- | --- |
| Atlanta | + 1.404.551.3212 |
| Boston | + 1.617.532.0920 |
| Chicago | + 1.312.675.0545 |
| Montreal | + 1.514.847.7506 |
| Monterrey | + 52.81.1253.4020 |
| New York | + 1.212.804.3901 |
| San Francisco | + 1.415.836.8800 |
| Sao Paulo | + 55.11.3706.1360 |
| Stamford | +1.203.325.5630 |
| Toronto | + 1.416.628.1007 |

## Europe, Middle East & Africa

Cape Town + 27.21.673.0100

Frankfurt + 49.69.133.859.00

Geneva + 41.22.817.9777

London + 44.20.7618.2222

Milan + 39.02.5849.0415

Paris 0800.91.59.17 (toll free)

## Asia Pacific

China North 10800.852.1032 (toll free)

China South 10800.152.1032 (toll free)

Hong Kong + 852.2844.9333

Seoul 00798.8521.3392 (toll free)

Singapore 800.852.3749 (toll free)

Sydney + 61.2.9033.9333

Tokyo + 81.3.5226.8222

## Notice and Disclaimer

This document and all of the information contained in it, including without limitation all text, data, graphs, charts (collectively, the “Information”) is the property of MSCI Inc. or its subsidiaries (collectively, “MSCI”), or MSCI’s licensors, direct or indirect suppliers or any third party involved in making or compiling any Information (collectively, with MSCI, the “Information Providers”) and is provided for informational purposes only. The Information may not be reproduced or redisseminated in whole or in part without prior written permission from MSCI.

The Information may not be used to create derivative works or to verify or correct other data or information. For example (but without limitation), the Information may not be used to create indices, databases, risk models, analytics, software, or in connection with the issuing, offering, sponsoring, managing or marketing of any securities, portfolios, financial products or other investment vehicles utilizing or based on, linked to, tracking or otherwise derived from the Information or any other MSCI data, information, products or services.

The user of the Information assumes the entire risk of any use it may make or permit to be made of the Information. NONE OF THE INFORMATION PROVIDERS MAKES ANY EXPRESS OR IMPLIED WARRANTIES OR REPRESENTATIONS WITH RESPECT TO THE INFORMATION (OR THE RESULTS TO BE OBTAINED BY THE USE THEREOF), AND TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, EACH INFORMATION PROVIDER EXPRESSLY DISCLAIMS AL IMPLIED WARRANTIES (INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES OF ORIGINALITY, ACCURACY, TIMELINESS, NON-INFRINGEMENT, COMPLETENESS, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE) WITH RESPECT TO ANY OF THE INFORMATION.

Without limiting any of the foregoing and to the maximum extent permitted by applicable law, in no event shall any Information Provider have any liability regarding any of the Information for any direct, indirect, special, punitive, consequential (including lost profits) or any other damages even if notified of the possibility of such damages. The foregoing shall not exclude or limit any liability that may not by applicable law be excluded or limited, including without limitation (as applicable), any liability for death or personal injury to the extent that such injury results from the negligence or willful default of itself, its servants, agents or sub-contractors.

Information containing any historical information, data or analysis should not be taken as an indication o guarantee of any future performance, analysis, forecast or prediction. Past performance does not guarantee future results.

None of the Information constitutes an offer to sell (or a solicitation of an offer to buy), any security, financia product or other investment vehicle or any trading strategy.

You cannot invest in an index. MSCI does not issue, sponsor, endorse, market, offer, review or otherwise express any opinion regarding any investment or financial product that may be based on or linked to the performance of any MSCI index.

MSCI’s indirect wholly-owned subsidiary Institutional Shareholder Services, Inc. (“ISS”) is a Registered Investment Adviser under the Investment Advisers Act of 1940. Except with respect to any applicable products or services from ISS (including applicable products or services from MSCI ESG Research, which are provided by ISS), neither MSCI nor any of its products or services recommends, endorses, approves or otherwise expresses any opinion regarding any issuer, securities, financial products or instruments or trading strategies and neither MSCI nor any of its products or services is intended to constitute investment advice or a recommendation to make (or refrain from making) any kind of investment decision and may not be relied on as such.

The MSCI ESG Indices use ratings and other data, analysis and information from MSCI ESG Research. MSCI ESG Research is produced by ISS or its subsidiaries. Issuers mentioned or included in any MSCI ESG Research materials may be a client of MSCI, ISS, or another MSCI subsidiary, or the parent of, or affiliated with, a client of MSCI, ISS, or another MSCI subsidiary, including ISS Corporate Services, Inc., which provides tools and services to issuers. MSCI ESG Research materials, including materials utilized in any MSCI ESG Indices or other products, have not been submitted to, nor received approval from, the United States Securities and Exchange Commission or any other regulatory body.

Any use of or access to products, services or information of MSCI requires a license from MSCI. MSCI, Barra, RiskMetrics, IPD, ISS, FEA, InvestorForce, and other MSCI brands and product names are the trademarks, service marks, or registered trademarks of MSCI or its subsidiaries in the United States and other jurisdictions. The Global Industry Classification Standard (GICS) was developed by and is the exclusive property of MSCI and Standard & Poor’s. “Global Industry Classification Standard (GICS)” is a service mark of MSCI and Standard & Poor’s.

## About MSCI

MSCI Inc. is a leading provider of investment decision support tools to investors globally, including asset managers, banks, hedge funds and pension funds. MSCI products and services include indices, portfolio risk and performance analytics, and governance tools.

The company’s flagship product offerings are: the MSCI indices with close to USD 7 trillion estimated to be benchmarked to them on a worldwide basis1; Barra multi-asset class factor models, portfolio risk and performance analytics; RiskMetrics multi-asset class market and credit risk analytics; IPD real estate information, indices and analytics; MSCI ESG (environmental, social and governance) Research screening, analysis and ratings; ISS governance research and outsourced proxy voting and reporting services; FEA valuation models and risk management software for the energy and commodities markets; and CFRA forensic accounting risk research, legal/regulatory risk assessment, and due-diligence. MSCI is headquartered in New York, with research and commercial offices around the world.

1As of September 30, 2012, as published by eVestment, Lipper and Bloomberg on January 31, 2013

Apr 2013