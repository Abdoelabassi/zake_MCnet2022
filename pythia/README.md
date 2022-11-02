# Pythia Tutorial

## MONDAY & TUESDAY

Contact: Leif Lönnblad

worksheet8300.pdf is the general worksheet for getting started with
Pythia version 8.3. Just follow the step-by-step instructions to
downlad and install, and then write and run example programs.

## TUESDAY

To generate W-events and use the MY_W_ANALYSIS it is easiest to use
the docker container, and the ready-built `pythia8-main93` program
there, with (after having sourced the `setup.sh` file in the
"project" directory on the tutorial git)

```
  dockerdo pythia8-main93 -c main93.cmnd -o test
```

This will produce a `test.log` and a `test.yoda` file for the run
specified in `main93.cmnd`. The default `main93.cmnd` file generates
minumum bias events and you need to edit it to get what you want. In
particular you will need to change

```
Beams:eCM = 13000.            ! CM energy of collision

! SoftQCD:all = on            ! We will not use Soft QCD
WeakSingleBoson:ffbar2W = on  ¡ We are interested in W-production

24:onMode = off               ! And we are only interested in 
24:onIfAny = 11 12 13 14      ! leptonic decays

Main:numberOfEvents = 200     ! You probably want more events ...

Main:runRivet = on            ! Run Rivet (specify analyses below)
Main:analyses = MY_W_ANALYSIS ! And use only this analysis
```

After thes changes you can run again and make the plots:

```
dockerdo pythia8-main93 -c main93.cmnd -o Wtest
dockerdo rivet-mkhtml --pwd -o Wtest Wtest.yoda
```

  

