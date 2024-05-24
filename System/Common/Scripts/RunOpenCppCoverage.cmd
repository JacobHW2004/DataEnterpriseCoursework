title "Generate coverage reports" 
::Runs OpenCppCoverage on the unit test exes
::Format is
::opencppcoverage --sources=SOURCE CODE LOCATION FOR THE FILE YOU'VE TESTED --excuded_sources=EXCUDED SOURCE IN THE SOURCE DIRECTOR --export_type=binary:FILENAME.cov --excluded_line_regex "\s*else.*|\s*\}.*" --PATH TO UNIT TEST
::OpenCppCoverage will create a binary for each test then combine them in the last command. You'll need to add the binary filename to this last command or it won't get picked up

::Build server runs from the root
::Locally we run from the build folder (whatever the user names it)
::The build server is a lot more pernickety. CMake can't find the OpenCPPCoverage so we set the path manually
::The build server also doesn't like running off relative paths so we set the path for the files as well
echo "Build path =  %cd%"
echo "%1"
IF "%1"=="build-server" (
    echo "On build server"
    set ROOT=%cd%\Build\bin\debug
    set SOURCES=--sources=%cd%\Private --sources=%cd%\Public
    set COVERAGETOOLPATH="C:\Program Files\OpenCppCoverage\opencppcoverage"
) ELSE (
    echo "Not on build server"
    ::Locally we use relative paths because it's more flexible and doesn't cause issues like it does on the build server
    set ROOT="%cd%\bin\debug"
    set SOURCES=--sources=\Private --sources=\Public
    set COVERAGETOOLPATH=opencppcoverage
)

:::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Create the report
:::::::::::::::::::::::::::::::::::::::::::::::::::::::

echo "coverage tool path is %COVERAGETOOLPATH%"
echo "sources are %SOURCES%

%COVERAGETOOLPATH% %SOURCES% --export_type=binary:SIUnits.cov --excluded_line_regex "\s*else.*|\s*\}.*" -- %ROOT%\SITests.exe

:::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Merge unit tests into full coverage report
:::::::::::::::::::::::::::::::::::::::::::::::::::::::
%COVERAGETOOLPATH% ^
--input_coverage=SIUnits.cov ^
--export_type=cobertura:coverage.xml ^
--export_type=html:CoverageReport


