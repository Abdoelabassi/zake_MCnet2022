#!/usr/bin/env bash

VER="3.1.6"
#CONTAINER="rivet-herwig"
CONTAINER="rivet-pythia"
#CONTAINER="rivet-sherpa"

CMD="docker run -i --rm -u "`id -u $USER`":"`id -g`"  -v $PWD:$PWD -w $PWD hepstore/$CONTAINER:"$VER
# May need root access to run properly: uncomment line below
# CMD="sudo docker run -i --rm -u "`id -u $USER`":"`id -g`"  -v $PWD:$PWD -w $PWD hepstore/$CONTAINER:"$VER

# forward a command to the DOcker container
alias dockerdo="$CMD"

# use Python version from Docker image
alias python="$CMD python" 

# Rivet tools
alias rivet="$CMD rivet"
alias rivet-build="$CMD rivet-build"
alias rivet-merge="$CMD rivet-merge"
alias rivet-cmphistos="$CMD rivet-cmphistos"
alias rivet-mkanalysis="$CMD rivet-mkanalysis"
alias rivet-mkhtml="$CMD rivet-mkhtml"
alias make-plots="$CMD make-plots"

# YODA tools
alias yodamerge="$CMD yodamerge"
alias yodastack="$CMD yodastack"
alias yodascale="$CMD yodascale"
alias yodadiff="$CMD yodadiff"
alias yoda2flat="$CMD yoda2flat"
alias yodals="$CMD yodals"

# let Rivet find local libraries
export RIVET_ANALYSIS_PATH=`pwd`
export LHAPDF_DATA_PATH="${PWD}/PDFsets"

