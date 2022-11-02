BEGIN PLOT /MY_W_ANALYSIS/.*
LogX=1
LegendAlign=r
LegendXPos=0.95
END PLOT

BEGIN PLOT /MY_W_ANALYSIS/lepton_pT
XLabel=lepton $p_\mathrm{T}$ [GeV]
YLabel=$\mathrm{d}\sigma / \mathrm{d}p_\mathrm{T}$ [pb GeV$^{-1}$]
END PLOT

BEGIN PLOT /MY_W_ANALYSIS/met
XLabel=$p_\mathrm{T}^\mathrm{miss}$ [GeV]
YLabel=$\mathrm{d}\sigma / \mathrm{d}p_\mathrm{T}^\mathrm{miss}$ [pb GeV$^{-1}$]
END PLOT

BEGIN PLOT /MY_W_ANALYSIS/mT
XLabel=$m_\mathrm{T}$ [GeV]
YLabel=$\mathrm{d}\sigma / \mathrm{d}m_\mathrm{T}$ [pb GeV$^{-1}$]
END PLOT

BEGIN PLOT /MY_W_ANALYSIS/fid_xsec
LogY=0
LogX=0
LegendYPos=0.5
XLabel=$E_\mathrm{CMS} = 13$ TeV
YLabel=$\mathrm{d}\sigma$ [pb]
END PLOT

