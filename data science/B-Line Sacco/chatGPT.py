class Customer:
    def __init__(self):
        """Initialize customer details with user input"""
        #self.cusId = input("Enter Customer's ID: ")
        #self.cusName = input("Enter Customer's Name: ")
        #self.age = input("Enter Customer's Age: ")
        #self.gender = input("Enter Customer's Gender: ")


class Car:
    FUNCTIONING_CARS = ["KDE 324J", "KCT 783N", "KBL 127O", "KCK 209K", "KCH 954Y",
                        "KCW 790X", "KCJ 078K", "KBZ 341W", "KCA 309M", "KCE 782K",
                        "KDX 890C", "KDW 954F", "KCD 678U", "KDA 734V", "KCQ 954F",
                        "KBR 341W", "KCR 983T", "KDD 800T", "KDJ 476M", "KCX 874F",
                        "KDQ 094P", "KDM 311Q", "KCC 931Y"]

    BROKEN_CARS = ["KDM 498Q", "KDE 066P", "KBG 682S", "KCL 856Z", "KDE 089G",
                   "KBR 341W", "KBX 809R"]

    def car_status(self, cls, car_name):
        """Checks if a car is found in functioning or broken collection"""
        if car_name in cls.FUNCTIONING_CARS:
            return "Functioning"
        elif car_name in cls.BROKEN_CARS:
            return "Broken"
        else:
            return "Not Found"


class Trips:
    def __init__(self):
        self.car = Car()  # Create a car instance to check car status

        print("`````````````````````````````````````````````````")
        print("_____________B-Line Transport System_____________")
        print(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n")

        print("Available Destinations:")
        self.destinations = {
            1: "Thika",
            2: "Kiambu",
            3: "Machakos",
            4: "Nakuru",
            5: "Mombasa"
        }

        for key, destination in self.destinations.items():
            print(f"{key}. {destination}")

        self.choice = int(input("\nEnter Destination Number: "))

        # Predefined trip schedule
        self.schedule = {
            1: [("07:00", "KDE 324J"), ("09:00", "KCT 783N"), ("11:00", "KBL 127O")],
            2: [("07:00", "KCW 790X"), ("09:30", "KBG 682S"), ("12:00", "KCJ 078K")],
            3: [("07:00", "KDE 089G"), ("10:00", "KCE 782K"), ("13:00", "KDX 890C")],
            4: [("07:00", "KCD 678U"), ("07:30", "KDA 734V"), ("11:30", "KBX 809R")],
            5: [("07:00", "KDD 800T"), ("07:30", "KDJ 476M"), ("13:30", "KCX 874F")]
        }

        if self.choice in self.schedule:
            print(f"_____________Schedule Trips to {self.destinations[self.choice]}_____________\n")
            print("No  :  Departure Time   :   Car Plate")

            for idx, (time, car_plate) in enumerate(self.schedule[self.choice], 1):
                print(f"{idx}.  :  {time}            :   {car_plate}")

            self.choice1 = int(input("\nEnter Trip Number: "))
            self.select_trip()
        else:
            print("Invalid Choice!")

    def select_trip(self):
        """Check car status and confirm trip"""
        trip_list = self.schedule.get(self.choice, [])
        if 1 <= self.choice1 <= len(trip_list):
            time, self.car_name = trip_list[self.choice1 - 1]
            self.check_status()
        else:
            print("Invalid Trip Number!")

    def check_status(self):
        """Check if car is functional before confirming trip"""
        car_status = self.car.car_status(self.car_name)

        if car_status == "Functioning":
            print("✅ Successfully Confirmed on Trip.")
            print(f"Trip Details: Car {self.car_name} is assigned.")
        elif car_status == "Broken":
            print(f"❌ Trip Confirmation Failed! Car {self.car_name} is experiencing Mechanical Issues.")
            print("Please choose another trip.")
        else:
            print(f"❌ Car {self.car_name} is not found in our system.")



class Ticket(Customer, Trips):
    def __init__(self):
        Customer.__init__(self)
        Trips.__init__(self)
        self.car_name = "Not Assigned"  # Ensure car_name exists before generating the ticket

    def generate_ticket(self):
        """Generate and save trip ticket"""
        destination_name = self.destinations[self.choice - 1] if 1 <= self.choice <= len(self.destinations) else "Unknown"
        try:
            with open("ticket.txt", "w") as file:
                file.write("''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n")
                file.write("                B-Line Travelers Sacco                  \n")
                file.write(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n")
                file.write(f"Customer's ID: {self.cusId}\n")
                file.write(f"Customer's Name: {self.cusName}\n")
                file.write(f"Customer's Age: {self.age}\n")
                file.write(f"Customer's Gender: {self.gender}\n")
                file.write(f"Customer's Destination: {destination_name}\n")
                file.write(f"Trip's Car: {self.car_name}\n")
                file.write("'''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n")
            print("\n✅ Ticket Successfully Generated!")
        except Exception as e:
            print(f"❌ Error Saving Ticket: {e}")

    def check_status(self):
        """Check the status of the car and confirm trip"""
        car_status = Car.car_status(self.car_name)

        if car_status == "Functioning":
            print("Successfully Confirmed on trip.")
            self.car_name = self.car_name  # Assign car_name before generating the ticket
            self.generate_ticket()
        else:
            print("❌ Trip not available. Please select another vehicle.")

    def display_bill(self):
        """Display ticket details"""
        try:
            with open("ticket.txt", "r") as file:
                print("\n--- Ticket Details ---")
                print(file.read())
        except FileNotFoundError:
            print("❌ File Error: Ticket not found!")

if __name__ == "__main__":
    Ticket()
