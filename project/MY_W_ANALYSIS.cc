// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/DressedLeptons.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/DirectFinalState.hh"

namespace Rivet {


  /// @brief Simple W selection
  class MY_W_ANALYSIS : public Analysis {
  public:

    /// Constructor
    RIVET_DEFAULT_ANALYSIS_CTOR(MY_W_ANALYSIS);

    /// @name Analysis methods
    /// @{

    /// Book histograms and initialise projections before the run
    void init() {

      // Initialise and register projections
      const FinalState fs(Cuts::abseta < 4.9);

      //FastJets jetfs(fs, FastJets::ANTIKT, 0.4, JetAlg::Muons::NONE, JetAlg::Invisibles::NONE);
      //declare(jetfs, "jets");

      // FinalState of direct photons and bare muons and electrons in the event
      DirectFinalState photons(Cuts::abspid == PID::PHOTON);
      DirectFinalState bare_leps(Cuts::abspid == PID::MUON || Cuts::abspid == PID::ELECTRON);

      // Dress the bare direct leptons with direct photons within dR < 0.1,
      // and apply some fiducial cuts on the dressed leptons
      Cut lepton_cuts = Cuts::abseta < 2.5 && Cuts::pT > 20*GeV;
      DressedLeptons dressed_leps(photons, bare_leps, 0.1, lepton_cuts);
      declare(dressed_leps, "leptons");

      // Missing momentum
      declare(MissingMomentum(fs), "MET");

      // Book histograms
      book(_h["lep_pT"], "lepton_pT", logspace(20, 30.0, 300.));
      book(_h["met"],    "met",       logspace(20, 30.0, 300.));
      book(_h["mT"],     "mT",        logspace(20, 30.0, 300.));
      book(_c, "fid_xsec");

    }


    /// Perform the per-event analysis
    void analyze(const Event& event) {

      // Retrieve dressed leptons, sorted by pT
      const vector<DressedLepton>& leptons = apply<DressedLeptons>(event, "leptons").dressedLeptons();
      if (leptons.empty())  vetoEvent;

      // Retrieve clustered jets, sorted by pT, with a minimum pT cut
      //Jets jets = apply<FastJets>(event, "jets").jetsByPt(Cuts::pT > 30*GeV);

      // Remove all jets within dR < 0.2 of a dressed lepton
      //idiscardIfAnyDeltaRLess(jets, leptons, 0.2);

      const FourMomentum missingMom = apply<MissingMomentum>(event, "MET").missingMomentum();
      const double pTmiss = missingMom.pT();
      if (pTmiss < 30*GeV)  vetoEvent;

      const double massT = mT(leptons[0].mom(), missingMom);
      if (massT < 30*GeV)  vetoEvent;

      _h["lep_pT"]->fill(leptons[0].pT()/GeV);
      _h["met"]->fill(pTmiss/GeV);
      _h["mT"]->fill(massT/GeV);
      _c->fill();

    }


    /// Normalise histograms etc., after the run
    void finalize() {

      scale(_h, crossSectionPerEvent()/picobarn);
      scale(_c, crossSectionPerEvent()/picobarn);

    }

    /// @}


    /// @name Histograms
    /// @{
    map<string, Histo1DPtr> _h;
    CounterPtr _c;
    /// @}


  };


  RIVET_DECLARE_PLUGIN(MY_W_ANALYSIS);

}
