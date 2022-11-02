# Rivet tutorial: Analysis prototyping and multiweights

## MONDAY

Contact: Christian Gutschow

**NB: It would be advisable to follow the prerequisites (below) ahead of the tutorial to avoid bandwidth issues.**


## Prerequisites


For this tutorial, we will be using the latest Rivet Docker image. To download the image, simply type:

```
  docker pull hepstore/rivet:3.1.6
```

We have provided a little `setup.sh` script which will let you use the image software outside of the container

You can source the script like so

```
  source setup.sh
```

which should give you all relevant Rivet scripts on the command line. To check that it worked, try e.g.

```
  rivet --version
```

which should return `rivet v3.1.6`.

Alternatively, you can run the container interactively, e.g. like so

```
  docker container run -it hepstore/rivet:3.1.6 /bin/bash
```

If you would like to have access to your current directory also from within the container, 
you can also use the following variation of the above command:
```
  docker container run -it -v $PWD:$PWD -w $PWD hepstore/rivet-pythia:3.1.6 /bin/bash
```


In addition, we've prepared some HepMC event files for you to analyse.
It's advisable to download these ahead of the tutorial as well, which you can
download and untar as follows

```
   wget "https://rivetval.web.cern.ch/rivetval/TUTORIAL/truth-analysis.tar.gz" -O- | tar -xz --no-same-owner
```

You should see two files `Wjets13TeV_10k.hepmc.gz` and `Zjets13TeV_10k.hepmc.gz` 
in your local directory, corresponding to particle-level $`W`$+jets and $`Z`$+jets events in 
proton-proton collisons at a centre-of-mass energy of 13 TeV.


