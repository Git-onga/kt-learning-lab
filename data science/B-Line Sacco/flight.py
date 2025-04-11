import os


class Management:
    def __init__(self):
        main_menu()


class Details:
    name = ""
    gender = ""
    cId = 0

    def __init__(self):
        self.phone_no = 0
        self.age = 0
        self.city = ""

    def information(self, cId, name, age, city, gender):
        self.cId = cId
        self.name = name
        self.age = age
        self.city = city
        self.gender = gender
        print("Your Details Are Saved With Us\n")


class Registration:
    choice = 0
    charges = 0.0

    def flight(self, choice, flight_selection):
        flights = ["Dubai", "Canada", "UK", "USA", "Australia", "Europe"]

        self.choice = choice

        flight_options = {
            1: [("DUB - 498", "09-10-2022 08:00 AM", 14000),
                ("DUB - 672", "10-10-2022 04:00 AM", 12000),
                ("DUB - 432", "09-10-2022 14:00 PM", 10000)],
            2: [("CA - 456", "10-10-2022 08:00 AM", 17000),
                ("CA - 767", "11-10-2022 04:00 AM", 15000),
                ("CA - 989", "12-10-2022 14:00 PM", 9000)],
            3: [("UK - 798", "10-10-2022 12:00 AM", 30000)],
            4: [("US - 569", "14-10-2022 11:00 AM", 25000),
                ("US - 324", "15-10-2022 02:00 AM", 20000)],
            5: [("AU - 255", "11-10-2022 17:00 PM", 19000)],
            6: [("EU - 475", "13-10-2022 13:00 PM", 21000),
                ("EU - 682", "14-10-2022 20:00 PM", 16000)],
        }

        if self.choice in flight_options:
            if 1 <= flight_selection <= len(flight_options[self.choice]):
                _, _, self.charges = flight_options[self.choice][flight_selection - 1]
                print("\nYou have successfully booked your flight.")
            else:
                print("Invalid selection. Returning to flight menu.")
        else:
            print("Invalid input. Returning to main menu.")


class Ticket(Registration, Details):
    def bill(self):
        destinations = ["Dubai", "Canada", "UK", "USA", "Australia", "Europe"]
        destination = destinations[self.choice - 1] if 1 <= self.choice <= 6 else "Unknown"

        with open("records.txt", "w") as file:
            file.write("____________ onAIR AIRLINES ______________\n")
            file.write("____________ Ticket ______________\n")
            file.write(f"Customer ID: {self.cId}\n")
            file.write(f"Customer Name: {self.name}\n")
            file.write(f"Customer Gender: {self.gender}\n")
            file.write(f"Destination: {destination}\n")
            file.write(f"Flight Cost: Rs. {self.charges}\n")
        print("Ticket has been generated.")

    def dispbill(self):
        if os.path.exists("records.txt"):
            with open("records.txt", "r") as file:
                print(file.read())
        else:
            print("No ticket found.")


def main_menu():
    print("\n\tonAIR AIRLINES \n")
    print("\t____________ Main Menu ____________")
    print("1. Add customer details")
    print("2. Flight registration")
    print("3. Print ticket and charges")
    print("4. Exit")


if __name__ == "__main__":
    Management()
