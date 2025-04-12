import pandas as pd
# load a library to create a fomula for us
import statsmodels.formula.api as smf
# load a librabry for graph
import matplotlib.pyplot as plt

#===========================================
#        1. Enter data for Tarining

# make a dictionary of data of the temperature of the day and sales of ice cream 
data = {
    'temperature':[ 10, 7, 26, 28, 30, 25, 29, 31, 28, 31, 27, 29], 
    'ice_cream_sales':[ 1, 0, 14, 14, 23, 20,23, 26, 22, 30, 26, 36]
}

# place the data in a table
dataset = pd.DataFrame(data)

#===========================================
#        2. Create the model

# This says that ice_cream_sales is determined by temperature
formula = "ice_cream_sales ~ temperature"

# Note that we have created our model but it does not 
# have internal parameters set yet
# First, we define our formula using a special syntax
# Create the model, but don't train it yet
model = smf.ols(formula = formula, data = dataset)

if not hasattr(model, 'params'):
    print("Model selected but it does not have parameters set. We need to train it!")

#===========================================
#        3. Train  the model

# fits our data. This method does the hard work for us.
fitted_model = model.fit()

# Print information about our model now it has been fit
print("The following model parameters have been found:\n" +
    f"Line slope: {fitted_model.params[1]}\n"+ f"Line Intercept: {fitted_model.params[0]}")

#===========================================
#      4. Plot the graph (Optional)

plt.scatter(dataset["temperature"], dataset["ice_cream_sales"])
plt.plot(dataset["temperature"], fitted_model.params[1] * dataset["temperature"] + fitted_model.params[0], 'r', label='Fitted line')
plt.xlabel("temperature")
plt.ylabel("ice_cream_sales")
plt.show()

#===========================================
#     5. Use the model to estimate
    
# states the temperature of the day we are interested in
print("\n☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ")
print(f"Enter Today's temperature: ")
temp = int(input())
print("\n☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️ ☀️")

temperature = { 'temperature' : [temp] }

# Use the model to predict the number of ice cream sales for that day
approximate_ice_cream_sales = round(fitted_model.predict(temperature))

if approximate_ice_cream_sales[0] < 0:
    print("\n🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧")
    print("Today's Ice Creams Sales is likely to be: 0")
    print("🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧")
else: 
    print("\n🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧")
    print(f"Today's Ice Creams Sales is likely to be: {approximate_ice_cream_sales[0]}")
    print("🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧🍧")

