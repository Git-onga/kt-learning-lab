from tkinter.tix import Select


class Patient:
    def __init__(self):
        self.ID = input("Enter Id format(p_00n): ")
        self.name = input("Enter Patient's Name: ")
        self.age = input("Enter Patient's Age: ")
        self.gender = input("Enter Patient's Gender: ")

    def store_data(self):
        with open("patient.txt", "a") as file:

            file.write(f"Patient ID: {self.ID}\n")
            file.write(f"Patient's Name: {self.name}\n")
            file.write(f"Patient's Age: {self.age}\n")
            file.write(f"Patient's Gender: {self.gender}\n")

            file.write("-------------------------------------\n\n")


    def dis_data(self):

        print("'''''''''''''''''''''''''''''''''''''\n")
        print("          ONE HOPE HOSPITAL          \n")
        print(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n\n")

        try:
            with open("patient.txt", "r") as file:
                print(file.read())
        except FileNotFoundError:
            print("File not Found")

class Doctor:
    schedules = []

    def __init__(self):
        self.d_ID = input("Enter Doctor's ID (format d_00n: ")
        self.d_name = input("Enter doctors Name: ")
        self.d_gender = input("Enter Doctor's Gender: ")
        self.d_age = input("Enter Doctor's Age: ")
        self.d_speciality = input("Enter doctor's Medical Speciality: ")

    def doc_sche(self):
        self.schedules.append(self.d_name)

    def dis_sche(self):
        for schedule in self.schedules:
            print(schedule)

choice = int(input("Enter Number of Patients: "))

for i in range(choice):
    print("\n")
    d = Doctor()
    d.doc_sche()
    print("-------------------------------------\n")


d.dis_sche()