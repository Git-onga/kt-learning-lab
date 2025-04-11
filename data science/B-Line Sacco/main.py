class Customer:
    def __init__(self):
        """Initialize customer details with user input"""
        self.cusId = input("Enter Customer's ID: ")
        self.cusName = input("Enter Customer's Name: ")
        self.age = input("Enter Customer's Age: ")
        self.gender = input("Enter Customer's Gender: ")


class Car:
    FUNCTIONING_CARS = ["KDE 324J", "KCT 783N", "KBL 127O", "KCK 209K", "KCH 954Y",
                        "KCW 790X", "KCJ 078K", "KBZ 341W", "KCA 309M", "KCE 782K",
                        "KDX 890C", "KDW 954F", "KCD 678U", "KDA 734V", "KCQ 954F",
                        "KBR 341W", "KCR 983T", "KDD 800T", "KDJ 476M", "KCX 874F",
                        "KDQ 094P", "KDM 311Q", "KCC 931Y"]

    BROKEN_CARS = ["KDM 498Q", "KDE 066P", "KBG 682S", "KCL 856Z", "KDE 089G",
                   "KBR 341W", "KBX 809R"]
    
    def __init__(self):
        self.status: str = ""

    def car_status(self, car_name):
        """Checks if a car is found in functioning or broken collection"""
        if car_name in self.FUNCTIONING_CARS:
            self.status = "Functioning"
        elif car_name in self.BROKEN_CARS:
            self.status = "Broken"
        else:
            self.status = "Not Found"
    
    def check_status(self, car_name, choice1):
        self.car_status(car_name)
        if self.status == "Functioning":
            print("Successfully Confirmed on trip.")
            print(f"{choice1}  :  07:00            :   {car_name}      :          08:30")
        elif self.status == "Broken":
            print("Trip Confirmation Failed.")
            print(f"{car_name} is experiencing Mechanical Issues at the Moment.")
            print(f"Please Consider our Other Schedule Trips")
        else:
            print(f"{car_name} is not a Vehicle in our Sacco")
    

class Trips:
   
    def __init__(self):

        self.car_name = ""
        print("'''''''''''''''''''''''''''''''''''''''''''''''''")
        print("_____________B-Line Transport System_____________")
        print(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n")


        print("The following are the Destination\n")
        self.destinations = ["1.Thika", "2.Kiambu", "3.Machakos","4.Nakuru", "5.Mombasa"]

        for destination in self.destinations:
            print(destination)

        self.choice = int(input("\nEnter Destination: "))

        match self.choice:
            case 1:
                print("_____________Schedule Trips to Thika_____________\n")
                print("No  :  Departure Time   :   Car Plate     :   Arrival Time")
                print("1.  :  07:00            :   KDE 324J      :          08:30")
                print("2.  :  09:00            :   KCT 783N      :          10:30")
                print("3.  :  11:00            :   KBL 127O      :          12:30")
                print("4.  :  13:00            :   KDM 498Q      :          14:30")
                print("5.  :  15:00            :   KCK 209K      :          16:30")
                print("6.  :  17:00            :   KCH 954Y      :          18:30")
                print("7.  :  19:00            :   KDE 066P      :          20:30")

                self.choice1 = 2
                self.charges = 100
                print(self.choice1)

                if self.choice1 == 1:
                    self.car_name = "KDE 324J"
                    Car.check_status(self.choice1,self.car_name)
                elif self.choice1 == 2:
                    self.car_name = "KCT 783N"
                    Car.check_status(self.choice1, self.car_name)
                elif self.choice1 == 3:
                    self.car_name = "KBL 127O"
                    Car.check_status(self.car_name,self.car_name)
                elif self.choice1 == 4:
                    self.car_name = "KDM 498Q"
                    Car.check_status(self.car_name,self.car_name)
                elif self.choice1 == 5:
                    self.car_name = "KCK 209K"
                    Car.check_status(self.car_name,self.car_name)
                elif self.choice1 == 6:
                    self.car_name = "KCH 954Y"
                    Car.check_status(self.car_name, self.car_name)
                elif self.choice1 == 7:
                    self.car_name = "KDE 066P"
                    Car.check_status(self.car_name, self.car_name)
                else:
                    print("INVALID CHOICE!!")

            case 2:
                print("_____________Schedule Trips to Kiambu_____________\n")
                print("No   :  Departure Time   :   Car Plate     :   Arrival Time")
                print("1.   :  07:00            :   KCW 790X      :          09:00")
                print("2.   :  09:30            :   KBG 682S      :          11:30")
                print("3    :  12:00            :   KCJ 078K      :          14:00")
                print("4.   :  14:30            :   KCL 856Z      :          16:30")
                print("5.   :  17:00            :   KBZ 341W      :          19:00")
                print("6.   :  19:30            :   KCA 309M      :          21:30")

                self.choice1 = int(input("\nEnter Trip Number: "))
                self.charges = 200

                if self.choice1 == 1:
                    self.car_name = "KCW 790X"
                    Car.check_status(self.car_name)

                elif self.choice1 == 2:
                    self.car_name = "KBG 682S"
                    Car.check_status(self.car_name)

                elif self.choice1 == 3:
                    self.car_name = "KCJ 078K"
                    Car.check_status(self.car_name)

                elif self.choice1 == 4:
                    self.car_name = "KCL 856Z"
                    Car.check_status(self.car_name)

                elif self.choice1 == 5:
                    self.car_name = "KBZ 341W"
                    Car.check_status(self.car_name)

                elif self.choice1 == 6:
                    self.car_name = "KCA 309M"
                    Car.check_status(self.car_name)

                else:
                    print("INVALID CHOICE!!")

            case 3:
                print("_____________Schedule Trips to Machakos_____________\n")
                print("No   :  Departure Time   :   Car Plate     :   Arrival Time")
                print("1.   :  07:00            :   KDE 089G      :          09:30")
                print("2.   :  10:00            :   KCE 782K      :          12:30")
                print("3    :  13:00            :   KDX 890C      :          15:30")
                print("4.   :  16:00            :   KDW 954F      :          18:30")
                print("5.   :  19:00            :   KBR 341W      :          21:30")

                self.choice1 = int(input("\nEnter Trip Number: "))
                self.charges = 400

                if self.choice1 == 1:
                    self.car_name = "KDE 089G"
                    Car.check_status(self.car_name)

                elif self.choice1 == 2:
                    self.car_name = "KCE 782K"
                    Car.check_status(self.car_name)

                elif self.choice1 == 3:
                    self.car_status = "KDX 890C"
                    Car.check_status(self.car_name)

                elif self.choice1 == 4:
                    self.car_name = "KDW 954F"
                    Car.check_status(self.car_name)

                elif self.choice1 == 5:
                    self.car_name = "KBR 341W"
                    Car.check_status(self.car_name)

                else:
                    print("INVALID CHOICE!!")

            case 4:
                print("_____________Schedule Trips to Nakuru_____________\n")
                print("No   :  Departure Time   :   Car Plate     :   Arrival Time")
                print("1.   :  07:00            :   KCD 678U      :          11:00")
                print("2.   :  07:30            :   KDA 734V      :          11:30")
                print("3    :  11:30            :   KBX 809R      :          15:30")
                print("4.   :  12:00            :   KCQ 954F      :          16:00")
                print("5.   :  16:00            :   KBR 341W      :          20:00")
                print("6.   :  16:30            :   KCR 983T      :          20:30")

                self.choice1 = int(input("\nEnter Trip Number: "))
                self.charges = 400

                if self.choice1 == 1:
                    self.car_name = "KCD 678U"
                    Car.check_status(self.car_name)

                elif self.choice1 == 2:
                    self.car_name = "KDA 734V"
                    Car.check_status(self.car_name)

                elif self.choice1 == 3:
                    self.car_name = "KBX 809R"
                    Car.check_status(self.car_name)

                elif self.choice1 == 4:
                    self.car_name = "KCQ 954F"
                    Car.check_status(self.car_name)

                elif self.choice1 == 5:
                    self.car_name = "KBR 341W"
                    Car.check_status(self.car_name)

                elif self.choice1 == 6:
                    self.car_name = "KCR 983T"
                    Car.check_status(self.car_name)

                else:
                    print("INVALID CHOICE!!")

            case 5:
                print("_____________Schedule Trips to Mombasa_____________\n")
                print("No   :  Departure Time   :   Car Plate     :   Arrival Time")
                print("1.   :  07:00            :   KDD 800T      :          13:00")
                print("2.   :  07:30            :   KDJ 476M      :          13:30")
                print("3    :  13:30            :   KCX 874F      :          19:30")
                print("4.   :  14:00            :   KDQ 094P      :          20:00")
                print("5.   :  20:30            :   KDM 311Q      :          02:30")
                print("6.   :  21:00            :   KCC 931Y      :          03:00")

                self.choice1 = int(input("\nEnter Trip Number: "))
                self.charges = 400

                if self.choice1 == 1:
                    self.car_name = "KDD 800T"
                    Car.check_status(self.car_name)
                elif self.choice1 == 2:
                    self.car_name = "KDJ 476M"
                    Car.check_status(self.car_name)

                elif self.choice1 == 3:
                    self.car_name = "KCX 874F"
                    Car.check_status(self.car_name)

                elif self.choice1 == 4:
                    self.car_name = "KDQ 094P"
                    Car.check_status(self.car_name)

                elif self.choice1 == 5:
                    self.car_name = "KDM 311Q"
                    Car.check_status(self.car_name)

                elif self.choice1 == 6:
                    self.car_name = "KDM 311Q"
                    Car.check_status(self.car_name)

                else:
                    print("INVALID CHOICE!!")

                print("Press any key to go back to the main menu ")



class Ticket(Customer, Trips):
    def generateTicket(self):
        self.destination: str

        with open("ticket.txt", "w") as file:
            file.write("''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n")
            file.write("                B-Line Travelers Sacco                  \n")
            file.write(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n")

            file.write("Customer's ID: {self.cusId}\n")
            file.write("Customer's Name: {self.cusName}\n")
            file.write("Customer's Age: {self.age}\n")
            file.write("Customer's gender: {self.gender}\n")



            file.write("Customer's Destination: {destination}\n")
            file.write("Trip's Car: {self.car_Name}\n")
            file.write("Trip's cost: {self.charges}\n")
            file.write("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n")

    def display_bill(self):
        try:
            with open("records.txt", "r") as file:
                print("\n--- Ticket Records ---")
                print(file.read())  # Read and print file content
        except FileNotFoundError:
            print("❌ File Error: records.txt not found!")

c = Trips()