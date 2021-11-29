import csv

def populate_data(filename: str) -> list:
    data = list() #const 
    line = 0
    print("Reading data . . .")
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            data.append(row)
            line += 1
    print("Read {0} line(s) of data".format(line))
    return data

aggreated_data = populate_data('aggreated-data.csv')
print(aggreated_data)