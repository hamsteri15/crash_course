#include <iostream>

#include "person.hpp"

int main(void) {
    /** Person class' constructor takes two arguments: name and birthyear **/
    Person kalle("Kalle Kankkunen", 1996);
    Person ville("Ville Vinkkunen", 1992);
    Person liisi("Liisi Pirinen", 1950);

    std::cout << kalle.get_name() << " is " << kalle.get_age(2019) << " years old." << std::endl;
    std::cout << ville.get_name() << " is " << ville.get_age(2019) << " years old." << std::endl;
    std::cout << liisi.get_name() << " is " << liisi.get_age(2019) << " years old." << std::endl;
}
