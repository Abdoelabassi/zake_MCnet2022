#! /usr/bin/env python

import yoda
from math import sqrt

fname = 'Rivet.yoda.gz'
hists = yoda.read(fname)
hname = '/MY_W_ANALYSIS/lepton_pT'
hfid = '/MY_W_ANALYSIS/fid_xsec'
hists[hfid] = yoda.Scatter1D()
hists[hfid].setAnnotation('Path', hfid)
v = hists[hname].integral()
e = sqrt(hists[hname].sumW2())
hists[hfid].addPoint(v, [e,e])
    
yoda.writeYODA(hists, fname.split('.yoda')[0] + '_mod.yoda.gz')
