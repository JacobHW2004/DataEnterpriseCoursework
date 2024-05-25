# SI Units Repo 

## Contents
   [Description](#description)<br>
   [Setup](#setup)<br>
   [Testing](#testing)<br>
   [Code Coverage](#code-coverage)<br>
   [Support](#support)<br>

<a name=description></a>
## Description

This repo holds the SI Units for the ECRS MK2 product. These classes contain implementations both base and derived SI units. Find out more information about SI Units here: [International System of Units](https://en.wikipedia.org/wiki/International_System_of_Units).

The repo currently implements the following units: 


|  Unit                         | Symbol                       | Quantity                     |
|-------------------------------|------------------------------|------------------------------|
| Radian                        | rad                          | Angle                        |
| RadianSquared                 | rad<sup>2</sup>              | Variance in Angle            |
| RadianPerSecond               | rad/s                        | Angular velocity             |
| RadianPerSecondSquared        | rad/s<sup>2</sup>            | Angular acceleration         |
| Degree                        | deg                          | Angle                        |
| Meter                         | m                            | Length                       |   
| MeterSquared                  | m<sup>2</sup>                | Variance in Length           | 
| MeterPerSecond                | m/s                          | Speed                        |  
| MeterPerSecondSquared         | m/s<sup>2</sup>              | Acceleration                 |  
| MeterSquaredPerSecondSquared  | m<sup>2</sup>/s<sup>2</sup>  | Variance in Acceleration     |  
| SquareMeter                   | m<sup>2</sup>                | Area                         |  
| CubicMeter                    | m<sup>3</sup>                | Volume                       |  
| Hertz                         | Hz                           | Frequency                    |  
| HetrzPerSecond                | Hz/s                         | Frequency Drift              |  
| HertzPerSecondSquared         | Hz/s<sup>2</sup>             | N/A                          |  
| AmplitudePower                | W                            | Power, Radiant flux          |
| Decibel                       | dB                           | Logarithmic ratio quantities |  
| Second                        | s                            | Time                         |  
| SecondSquared                 | s<sup>2</sup>                | N/A                          |  

<a name=setup></a>
## Setup

The SIunits repo uses the following repos:

* [scripts](http://desuk27was045v:7990/projects/vantage/repos/scripts)
   * Develop branch
   * The scripts and tools used within the Vantage pipeline.

These repos will need to be submoduled before building the application.

Run a git bash terminal with Admin Rights and navigate to the SIUnits repo you would like to build. Then enter the following command:

`git submodule update --init --recursive --progress --remote`


<a name=testing></a>
## Testing

Tests for the SI Units can be found in the __Tests__ folder. 

The SIUnitsLibraryTest.cpp file includes every .h file in the si-units Public folder. It's used for checking that the SI Units can be constructed. If a new SI Unit is added (or deleted) you should update this file.
__This is a manual process__
In addition, the Tests folder contains unit tests for the SIUnits source files.  An executable is generated for the Tests when cmake is run.


<a name=code-coverage></a>
## Code coverage

Code coverage is run against the Unit Test exes using OpenCppCoverage. To do this

1. Follow the steps above to generate (and build) the unit tests
2. Run the following command
`cmake --build . --target Coverage`

Code coverage results will be outputed to the CoverageReport directory in your build folder.

__Note__ Running code coverage will also run the unit tests

__Another note__ Don't run code coverage in release mode. In release the code is optimised so you'll get weird unit test results

### Implementation details
The following RegEx is ran with the code coverage. OpenCppCoverage will mark else and } as not covered because of the way Visual Studio builds up the code. See the OpenCppCoverage FAQ for more details.
`\s*else.*|\s*\}.*`


<a name=support></a>
## Support

This repo is currently supported by Team Vantage.

