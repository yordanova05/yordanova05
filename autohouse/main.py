from class_autohouse import AutoHouse
from class_car import Car
from class_client import Client
from class_employee import Employee
from class_manager import Manager

def main():
    autohouse = AutoHouse("Seviche", 2012)

    car1 = Car("Porshe", "GT3 RS", 2022, "purple", 11000, 900, 500000, 10)
    car2 = Car("BMW", "m3", 2004, "red", 3500000, 150, 6000, 4)
    car3 = Car("BMW", "m5", 2008, "black", 2800000, 185, 9500, 5)
    car4 = Car("Audi", "RS8", 2015, "blue", 194000, 200, 15000, 7)

    employee1 = Employee(98, "Ivan", "Ivanov", "Ivanov", 7, 3700)
    employee2 = Employee(4, "Georgi", "Ivailov", "Georgiev", 9, 4700)
    employee3 = Employee(133, "Maria", "Hristova", "Petkova", 2, 2100)
    employee4 = Employee(177, "Viktor", "Georgiev", "Stoyanov", 3, 2300)

    client1 = Client(55, "Yoanna", "Raikova", "Kichkova", 3000)

    print(autohouse.house_info())
    print("------------")
    print(autohouse.add_auto(car1))
    print(autohouse.add_auto(car2))
    print(autohouse.add_auto(car3))
    print(autohouse.add_auto(car4))

    print(autohouse.add_client(client1))

    print(autohouse.add_employee(employee1))
    print(autohouse.add_employee(employee2))
    print(autohouse.add_employee(employee3))
    print(autohouse.add_employee(employee4))

    print(employee1.promote())
    print("------------")
    print(employee3.promote())
    print("------------")
    print(employee3.info())
    print("------------")

    print(client1.info())
    print("------------")
    print(car3.car_leasing_info())
    print("------------")
    print(client1.show_balance())
    print("------------")
    print(client1.show_purchases())
    print("------------")
    print(autohouse.sell_car(car3,client1))
    print("------------")
    print(autohouse.show_brands())
    print("------------")

    print(autohouse.show_managers())
    print("------------")
    print(autohouse.show_employees())
    print("------------")
    print(autohouse.show_cars())
    print("------------")

    print(autohouse.paying_client(client1,600))
    print("------------")
#PROBVAI SE DA PREDSTAVISH DANNITE V TABLICA V EXEL!!!

if __name__ == "__main__":
    main()