import csv
import sys

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


#This function will take at most O(m*n) where m = size of data and n = size of characteristics
def find_probability(data, interest, characteristics):
    prior = 0                   #P(Y = interest)                                                                                O(1)
    prob_likelihood_evd = 1     #P(C1 | Y = interest) * P(C2 | Y = interest) * P(len(C) | Y = interest)                         O(1)
    prob_evd = 1                #P(C1) * P(C2) * P(len(C))  {note that C = characteristics}                                     O(1)
    total = data[len(data) - 1] #store the last index value as total since it contains the total for all the info               O(1)

    for data_idx in range(len(data) - 1):                                                                                      #O(m)
        if data[data_idx]['Type'].lower() == interest.lower():                                                                 #O(m - 1) -> O(m)
            curr_data = data[data_idx]                                                                                         #O(m - 1) -> O(m)
            prior = int(curr_data['Total']) / int(total['Total'])       #P(Y = interest)                                        O(m - 1) -> O(m)
            for characteristic in characteristics:                                                                             #O((m - 1) * n) -> O(m*n)
                prob_likelihood_evd *= (int(curr_data[characteristic]) / int(curr_data['Total']))                              #O((m - 1) * (n - 1)) -> O(m*n)
                prob_evd *= (int(total[characteristic]) / int(total['Total']))                                                 #O((m - 1) * (n - 1)) -> O(m*n)
            break                                                                                                              #O(1)
    print("Y = {3} prior: {0:.3f} prob_likelihood_evd: {1:.3f} prob_evd: {2:.3f} -> {4:.3f}".format(prior, prob_likelihood_evd, prob_evd, interest, (prob_likelihood_evd * prior) / prob_evd))
    return (prob_likelihood_evd * prior) / prob_evd                                                                            #O(1)
            

#This function will take at most O(p*m*n) where p = size of different possible prediction and m and n are defined in the above function
def predict(data,  characteristics):
    class_variables = ['Banana', 'Orange', 'Other']     #just hard coded for simplicity                                         O(1)
    class_predictions = []                                                                                                     #O(1)

    for class_variable in class_variables:                                                                                     #O(p)
        class_predictions.append(find_probability(data, class_variable, characteristics))                                      #O((p - 1)*O(find_probability)) -> O(p*(m*n))
    highest_prob = max(class_predictions)                                                                                      #O(p)

    return class_variables[class_predictions.index(highest_prob)]                                                              #O(p)



if __name__ == "__main__":
    characteristics = sys.argv[1:]
    if (len(characteristics) == 0): #meaning no command line arguments were provided
        print("Please enter characteristics as command line arguments! (0 provided Max 3)")
        sys.exit()
    if (len(characteristics) > 3):
        print("Too many characteristics (max 3)!")
        sys.exit()

    aggreated_data = populate_data('aggreated-data.csv')
    print("Given features: " + ", ".join(characteristics) + " Navie Bayes predicted {}".format(predict(aggreated_data, characteristics)))