from matplotlib import pyplot as plt
import pandas as pd

df_Data = pd.DataFrame({
    "student_ID": [1001,1002,1003,1004,1005,1006,1007,1008,1009,1010],
    "Hours_Studied": [10,4,8,3,12,6,11,5,7,9],
    "Attendance" : [90,60,75,55,95,70,88,65,80,85],
    "Gender" : ["Male","Female","Female","Male","Female","Male","Female","Male","Female","Male"],
    "Sleep_Hrs" : [7,5,6,4,7,6,6,5,6,6],
    "Study_Group" : ["Yes","No","Yes","No","Yes","No","Yes","No","Yes","Yes"],
    "Exam_Score" : [85,45,70,35,92,60,84,50,65,78]
})
print("\n ____________Collected Data___________________\n")
print(df_Data)

#             __Section A__

# a) Compute the mean Exam Score
mean_score = df_Data["Exam_Score"].mean()
print("\n ____________Mean Score___________________\n")
print(mean_score)

# b) Compute the Standard Deviation of Exam Score
std_score = df_Data["Exam_Score"].std()
print("\n ____________Standard Deviation___________________\n")
print(std_score)

# c) Compute the index of the Highest and lowest score
index_highest = df_Data["Exam_Score"].argmax
index_lowest =  df_Data["Exam_Score"].argmin


#           __Section B__

# a) Display the first five rows of the data
# print(df_Data.head())

# b) Summary of the data
# print(df_Data.describe())

# c) i) Filter students who studied more than 8 hours
print("\n ____Students who studied for more than 8 HRS_____\n")
print(df_Data.loc[df_Data.Hours_Studied >= 8])

# ii) Fliter students who had more than 85% attendance
print("\n ________Students who Scored more than 85%________\n")
print(df_Data.loc[df_Data.Attendance >= 85])

# iii) Filter students who are in a Study Group
print("\n ________Students who are in Study Group__________\n")
print(df_Data.loc[df_Data.Study_Group == "Yes"])

# d) Group Students by Gender and Compute their Average Hrs_Studied and Exm_Score
df_gender_score = df_Data.groupby("Gender")["Exam_Score"].mean()
df_gender_hrs = df_Data.groupby("Gender")["Hours_Studied"].mean()

print("\n ________Average Score grouped by Gender__________\n")
print(df_gender_score)
print("\n ______Average Study HRS grouped by Gender_________\n")
print(df_gender_hrs)

# e) Group Student by Study Group and compute the average Exm_Score
df_study_group = df_Data.groupby("Study_Group")["Exam_Score"].mean()

print("\n ________Mean of Studnts in Study group____________\n")
print(df_study_group)

# f) Add a pass column to show who passes and who failed
passes = pd.Series(df_Data["Exam_Score"] >= 50)
df_Data = pd.concat([df_Data, passes.rename("Pass")],axis=1)

print("\n _______Collected Data with Pass column___________\n")
print(df_Data)

# g) Count the number of Students who passed and Show pass rates per gender
print("\n _________Students rates per Gender_____________\n")
print(df_Data["Pass"].value_counts())
print(df_Data.groupby("Gender")["Pass"].value_counts())


# Get the variable to examine
var = df_Data['Exam_Score']

# Get statistics
min_val = var.min()
max_val = var.max()
mean_val = var.mean()
med_val = var.median()
mod_val = var.mode()[0]

print('Minimum:{:.2f}\nMean:{:.2f}\nMedian:{:.2f}\nMode:{:.2f}\nMaximum:{:.2f}\n'.format(min_val,mean_val,med_val,mod_val,max_val))

# Create a Figure
fig = plt.figure(figsize=(10,4))

# Plot a histogram
plt.hist(var)

# Add lines for the statistics
plt.axvline(x=min_val, color = 'gray', linestyle='dashed', linewidth = 2)
plt.axvline(x=mean_val, color = 'cyan', linestyle='dashed', linewidth = 2)
plt.axvline(x=med_val, color = 'red', linestyle='dashed', linewidth = 2)
plt.axvline(x=mod_val, color = 'yellow', linestyle='dashed', linewidth = 2)
plt.axvline(x=max_val, color = 'gray', linestyle='dashed', linewidth = 2)

# Add titles and labels
plt.title('Data Distribution')
plt.xlabel('Value')
plt.ylabel('Frequency')

# Show the figure
fig.show()

# Get the variable to examine
var = df_Data["Exam_Score"]

# Create a Figure
fig = plt.figure(figsize=(10,4))

# Plot a histogram
plt.boxplot(var)

# Add titles and labels
plt.title('Data Distribution')

# Show the figure
fig.show()