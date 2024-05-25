echo "Running unit tests using nose"
cd DataExporter
nosetests --with-xunit
echo "Running unit tests along with coverage"
coverage run -m unittest discover -s Test/
echo "getting coverage report"
coverage report -m
coverage xml
coverage html