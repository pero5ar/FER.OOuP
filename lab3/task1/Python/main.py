import sys
import os
import imp

def main():
    test()

def test():
    pets = []
    for my_module in os.listdir('plugins'):
        module_name, module_ext = os.path.splitext(my_module)
        if module_ext == '.py':
            ljubimac = myfactory(module_name)('Ljubimac '+ str(len(pets)))
            pets.append(ljubimac)

    for pet in pets:
        printGreeting(pet)
        printMenu(pet)

def myfactory(module_name):
    filename, pathname, description = imp.find_module(module_name, ["plugins"])
    module = imp.load_module(module_name, filename, pathname, description)
    return getattr(module, module_name)

def printGreeting(animal):
    print getattr(animal, "name") + " pozdravlja: " + getattr(animal, "greeting")

def printMenu(animal):
    print getattr(animal, "name") + " voli " + getattr(animal, "menu")+ "."

if __name__ == "__main__":
    main()
