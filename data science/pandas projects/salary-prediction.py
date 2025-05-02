from matplotlib import pyplot as plt
import pandas as pd
import statsmodels.formula.api as smf

# step 1: Collect the data
# Make a dictionary set of the data
data = {
    'YrsOfExp' : [2,54,33,24,5,25,
                  42,13,42,1,2,10,
                  23,42,15,23,36,17,
                  17,15,11,23,47,23
    ],
    'Salary' : [10000,70000,54000,31000,12000,29000,
                48000,22000,45000,10000,10000,22000,
                31000,47000,23000,32000,40000,25000,
                24000,20000,21000,31000,49000,25000
    ]
}

dataset = pd.DataFrame(data)

# print(dataset)

# Step 2: Create the Model
formula = "Salary ~ YrsOfExp"

model = smf.ols(formula=formula, data=dataset)

# Step 3: Train the Model
fitted_model = model.fit()

# Step 4: Plot the Graph
plt.scatter(dataset["YrsOfExp"], dataset["Salary"])
plt.plot(dataset["YrsOfExp"], fitted_model.params[1] * dataset["YrsOfExp"] + fitted_model.params[0], 'r', label ='Fitted line' )
plt.xlabel("Yrs Of Experince")
plt.ylabel("Salary")
# plt.show()

# Step 5: Use the Model to make Prediction
print("#################################")
print("Enter your Years Of Experince")
Exp = int(input())

YrsOfExp = {"YrsOfExp" : [Exp]}

Salary = round(fitted_model.predict(YrsOfExp))

print("\n################################")
print("\n   Expected Salary is: ")
print(Salary)