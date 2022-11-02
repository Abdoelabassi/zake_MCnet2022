# Common project

**NB: It would be advisable to follow the prerequisites (below) ahead of the tutorial to avoid bandwidth issues.**


## Prerequisites


For this tutorial, we will be using Docker. To download the image for a given generator and Rivet, simply type e.g.:

```
  docker pull hepstore/rivet-pythia:3.1.6
```

or a similar command for the `rivet-herwig` and `rivet-sherpa` images.
We have provided a little `setup.sh` script which will let you use the image software outside of the container

You can source the script like so

```
  source setup.sh
```

which should give you access to all relevant command-line tools. To check that it worked, try e.g.

```
  rivet --version
```

which should return `rivet v3.1.6`. 
You can pass other commands to the Docker environment using the `dockerdo` alias, e.g.

```
dockerdo pythia8-main93 -c mysetup.cmd
```

Alternatively, you can run the container interactively, e.g. like so

```
  docker container run -it hepstore/rivet-pythia:3.1.6 /bin/bash
```
If you would like to have access to your current directory also from within the container, 
you can also use the following variation of the above command:
```
  docker container run -it -v $PWD:$PWD -w $PWD hepstore/rivet-pythia:3.1.6 /bin/bash
```

In order to exit from the Docker shell, just type `exit`.

Have fun!

## Can't find LHAPDF?

If you get a Python `ImportError` for the `import lhapdf` line in the scripts, try this workaround:

```
export PYTHONPATH=/usr/local/lib/python3.8/site-packages/LHAPDF-6.5.1-py3.8-linux-x86_64.egg:$PYTHONPATH
```

## Missing a PDFs?

The Docker containers might not provide every PDF set you're interested in.
The PDF sets can be downloaded from the LHAPDF website e.g. like so
```
wget http://lhapdfsets.web.cern.ch/lhapdfsets/current/NNPDF30_nnlo_as_0118.tar.gz  -P PDFsets -O- | tar --no-same-owner -xz -C PDFsets
```
which would download the `NNPDF30_nnlo_as_0118` set into the local `PDFsets` directory.
The LHAPDF tool will be able to find these by setting the following environment variable
```
export LHAPDF_DATA_PATH="${PWD}/PDFsets"
```
which the `setup.sh` script will also do for you.

## Reference data missing in the plots?

The file `MY_W_ANALYSIS.yoda.gz` includes some pseudodata
(generated with a Monte Carlo generator) that can be used
as a reference file. In order for the reference points to
be picked up by the Rivet plotting script, you might need
to set the following environment variable:

```
export RIVET_ANALYSIS_PATH=${PWD}
```
assuming the file is in your current working directory.

## Combining uncertainties from different YODA files or multiweights

We provide a little helper script `modelBuilder` which makes use of
the [YODA Python API](https://yoda.hepforge.org/pydoc/) in order to 
help you combine different variations (provided as separate files 
or as multiweights within the same file) to produce an new output 
YODA file with both statistical and generator uncertainties added 
in quadrature and reflected in the error bars.

An example command could look like this:
```
./modelBuilder -i nominal.yoda.gz -o modelA.yoda.gz --env "^MU.*MU.*PDF261000" --pdf "^MUR1_MUF1_PDF261.*" --env varUp.yoda.gz,varDown.yoda.gz
```
where the `-i` flag is used to specify the input file, 
the `-o` flag is used to specify the output file,
the `--pdf` flag is used to specify a 
[regular expression](https://en.wikipedia.org/wiki/Regular_expression)
to select a set of multiweights in the input file that
should be 
[combined into a PDF uncertainty](https://lhapdf.hepforge.org/codeexamples.html),
and the `--env` flag is used to construct two envelopes,
using (i) a regular expression that selects a set of multweights
in the inpout file which should be combined into an envelope
and (ii) using a list of explicit variation files that 
(together with the nominal input file) should be used to
construct the other envelope.

Instead of a regular expression, you can also provide
a comma separated list of weight names.

All uncertainty components will be added in quadrature,
together with the statistical uncertainty on the nominal
prediction in the input file and the error bars 
on the prediction in the output file will be increased
correspondingly.

The script also provides the flag `-n` to transfer the 
final uncertainty onto a different multiweight,
that is not the sample nominal weight, and use
its central values for the output file instead.

## Simple Chi2 tests 

In addition, we provide the little helper script
`findBestModel` which can be used to perform
[simple Chi2 tests](https://en.wikipedia.org/wiki/Reduced_chi-squared_statistic)
between different YODA files
against the provided reference YODA file
(`MY_W_ANALYSIS.yoda.gz`), identifying 
the model that has the "best" reduced Chi2
(i.e. the one closest to unity).

An example command could look like this:
```
./findBestModel --ref MY_W_ANALYSIS.yoda.gz modelA.yoda.gz modelB.yoda.gz modelC.yoda.gz
```

Note that the calculation of the p-value requires `scipy.stats` which is included in the Contur Docker image.

