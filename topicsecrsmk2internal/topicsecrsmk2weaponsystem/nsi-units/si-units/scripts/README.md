# Scripts
Various scripts to be used by developers and CI pipelines.  
Scripts should be project agnostic so they can be reused between teams. To facilitate this put project specific data such as paths, server information, confluence spaces, etc into a configuration file.  
Writing tests for new scripts is highly encouraged but it is understandable if they are omitted.
______________________________________________________________________________________________________________________________

## CMake
### Description
CMake can process scripts written in it's own [scripting language](https://cmake.org/cmake/help/v3.7/manual/cmake-language.7.html).
This allows moving repetive cmake statements into a function.  

### Modules
* __CustomTargets__: Functions to do common setup of targets and add them.
* __ExternalTools__: Targets created to run external programs.  
* __CompilerWarnings__: Specify warnings to enable [WIP] 
<br/>
<br/>
<br/>

____________________________________________________________________________________________________________________________
## DataExporter
### Description
It is desirable to view information in more human readable formats outwith the repo.  
Tasking developers to do this is problematic because they may do it incorrectly and then the exported data does not agree with the actual data.  
Also it is monkey work.

### Modules
* __PullRequestChecker__: Checks no red flags on a pull request and informs the reviewers if there are.  
* __ConfluenceUpdates__: Updates the test results in the scenario requirement tables and updates test summary table found on the component pages.
    * The scenario table is found using the id (scenarioTable) stored in the surrounding tag on Confluence. A status macro should be present in 
    the testResult column to update the status.
    * The test summary table is found using the id (testTable) stored in the surrounding tag on Confluence. A status macro should be present 
    in the last column of the table to update the status.
* __YogiRequirements__: This class calls the Yogi API to fetch all the Yogi Requirements in the confluence space. This data includes information about which page the requirement is located on and additional information such as related Jira issues.
* __TestReport__:This class fetches the test report from Jenkins and provides the test results for use within confluence.
* __ProjectParser__: Uses the project configuration file to set up the accounts for Bitbucket, Confluence, Jenkins and Jira.

### Unit Tests
Unit tests have been written using unittest.
The unit tests for the DataExporter can be run using nose.

In the project directory, run the following commands to generate an xml file that supports the Junit plugin in Jenkins:

**nosetests --with-xunit**

nosetests will find all tests in all sub-directories - it assumes that any file with test in it's name is a test file.

You need to have nose.py installed in order to be able to run this command.

### Test Coverage
Unit tests have been added to provide test coverage of the DateExporter code.
The coverage report can be run using the following commands in the project directory:

**coverage run -m unittest discover -s Test/**

**coverage report -m**

**coverage html**

**coverage xml**

This runs the unit tests and gives an html report index.html in the htmlcov directory.
It also generates an xml file that can be used by the Cobertura publisher plugin in Jenkins.
You need to have coverage.py installed in order to be able to run this command.

<br/>
<br/>
<br/>
 
______________________________________________________________________________________________________________________________
## Code Generators
### Description
Generate repetative code to help productivity, simplicity and consistency.
Code generation can be written in language (eg. C++ Templates) or outwith. The generators are written outwith.

### Modules
* __LCAUserFiles__: Generate lca user files from a human readable config file
* __ComponentMessaging__: Generate the LCAMessaging & TestMessaging layer
