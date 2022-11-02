# Tutorials for the MCnet Summer School in Zakopane (2022)

[WEBSITE: CRACOW SCHOOL OF THEORETICAL PHYSICS/MCNET SUMMER SCHOOL](https://indico.cern.ch/event/1104027/)

## Schedule

### MONDAY
* Getting started
* Brief introduction to [Rivet](rivet)
* Generator tutorials
  * [Herwig7](herwig)
  * [Pythia8](pythia)
  * [Sherpa](sherpa)

### TUESDAY
* [Common project](project)

### THURSDAY
* 2pm: [Madgraph](madgraph)
* 4pm: [Contur](contur)

### FRIDAY
* Presentation of the [common project](project)
* [Machine learning](ml4hep)


## Prerequisites

Most tutorials will be based on Docker.
If you are using MacOS or Windows, you will first need to create a DockerID at https://hub.docker.com/signup

Head to https://docs.docker.com/install for installation instructions.

You can check that Docker has installed properly by running the `hello-world` Docker image

        $ docker run hello-world

Some helpful commands:

`docker run [OPTIONS] IMAGE` to run an image; 
`docker ps` to list active containers; 
`docker image ls` to list available images/apps; 
`docker attach [OPTIONS] CONTAINER` to attach to a container

When you are running inside a container, you can use `CTLR-p CTLR-q` to detach from it and leave it running. 

Please see [tutorial-specific instructions](project#prerequisites) as well.


### Root privileges for Linux users

In case you're being asked for `sudo` privileges when trying to run Docker,
please see these [post-installation notes](https://docs.docker.com/engine/install/linux-postinstall/).

