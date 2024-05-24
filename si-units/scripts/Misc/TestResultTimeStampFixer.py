import xml.etree.ElementTree as ET
import sys
import os
from datetime import datetime

target_file_dir = "."
if (len(sys.argv) > 1 ):
    target_file_dir = sys.argv[1]


for filename in os.listdir(target_file_dir):

    if filename.endswith(".xml"): 

        filepath = target_file_dir + filename

        tree = ET.parse(filepath)

        root = tree.getroot()

        testsuite = root[0]

        split_current_time = str(datetime.now()).split(" ")

        new_timestamp = split_current_time[0]+"T"+split_current_time[1]+"Z"

        testsuite.set('timestamp',new_timestamp)

        tree.write(filepath)

        
    else:
        continue




