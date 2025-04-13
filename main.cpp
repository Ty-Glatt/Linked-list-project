#include "linked_list.hpp" 
#include <iostream>

// Calculates the multiplicative inverse of the first 20 prime numbers and adds them to A list.
void multiplicative_inverses_calc(LinkedList& multi_inverses_list){
    int prime_number[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};

    for(int i = 0; i < 20; i++){
        int prime = prime_number[i];
        double multiplicative_inverse = 1.0 / prime;
        multi_inverses_list.push_front(prime, multiplicative_inverse);
    }
}

// Finds the sum of all the values in the list by iterating through the list and adding each value to a sum variable.
double sum(LinkedList& multi_inverses_list){
    double sum = 0.0;
    Node* current = multi_inverses_list.get_head();
    while (current) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}


double smallest_calc(LinkedList& day_calculations){

    Node* current = day_calculations.get_head();
    double smallest = current->value;

    while(current) {
    if(current->value < smallest){
    smallest = current->value;
}
    current = current->next;
    }    
    return smallest;
}

double largest_calc(LinkedList& day_calculations){

    Node* current = day_calculations.get_head();
    double largest = current->value;

    while(current) {
    if(current->value > largest){
        largest = current->value;
}
    current = current->next;
    }
    return largest; 
}

int main() {
    std::cout << "Linked List Project" << std::endl;
    std::cout << "_____________________" << std::endl;
	std::cout << "Question 1:" << std::endl << std::endl;
    
    LinkedList multi_inverses_list;

    // Fills the multi_inverses_list with prime numbers as the keys and their multiplicative inverses as the values.
    // Then prints the multi_inverses_list.
    multiplicative_inverses_calc(multi_inverses_list);
    
    // Sorts the multi_inverses_list by the prime numbers.
    multi_inverses_list.selection_sort();

    std::cout << "Multiplicative Inverses List(Prime number, Multiplicative Inverse): " << std::endl;
    multi_inverses_list.print();
    
    // Uses the sum function to find the sum of the multiplicative inverses.
    double sum_of_multiplicative_inverses = sum(multi_inverses_list);
    std::cout << "Sum of the first 20 multiplicative inverses: " << sum_of_multiplicative_inverses << std::endl << std::endl;

    std::cout << "Question 2:" << std::endl << std::endl;
    
    LinkedList day_calculations;

    day_calculations.push_front(1, 365.25); //Julian
    day_calculations.push_front(2,  365.242); //Revised Julian
    day_calculations.push_front(3,  365.2425); //Gregorian
    day_calculations.push_front(4,  365.256); //Sidereal
    day_calculations.push_front(5,  365.259); //Anomalistic
    day_calculations.push_front(6,  354.37); //Lunar
    day_calculations.push_front(7,  365.256); //Gaussian
    day_calculations.push_front(8,  365.24219); //Tropical
    day_calculations.push_front(9,  346.62); //Draconic

    // Sorts the day_calculations list by the year type.
    day_calculations.bubble_sort();

    std::cout << "Day Calculations(Year type, Days in year): " << std::endl;
    day_calculations.print();

    double smallest = smallest_calc(day_calculations);
    double largest = largest_calc(day_calculations);
    double smallest_difference = smallest * 10000.0;
    double largest_difference = largest * 10000.0;
    double difference = largest_difference - smallest_difference;

    std::cout << "Smallest value: " << smallest << std::endl;
    std::cout << "Largest value: " << largest << std::endl;
    std::cout <<"the difference between the largest and smallest calculation in days when talking about 10,000 years is: " << difference << std::endl << std::endl;


    std::cout << "Question 3:" << std::endl << std::endl;

    LinkedList Top_15_companies;

    // Fills the Top_15_companies list with the top 15 companies and their stock prices.
    Top_15_companies.push_front(1, 184.87); // Amazon
    Top_15_companies.push_front(2, 159.40); // Alphabet inc, class C
    Top_15_companies.push_front(3, 157.14); // Alphabet inc, class A
    Top_15_companies.push_front(4, 543.57); // Meta
    Top_15_companies.push_front(5, 198.15); // Apple
    Top_15_companies.push_front(6, 388.45); // Microsoft
    Top_15_companies.push_front(7, 110.93); // Nvidia
    Top_15_companies.push_front(8, 162.24); // MongoDB
    Top_15_companies.push_front(9, 35.08);  // ON semiconductor
    Top_15_companies.push_front(10, 115.17); //Biogen Inc.
    Top_15_companies.push_front(11, 33.33); // Global Foundries
    Top_15_companies.push_front(12, 148.80); // CDW
    Top_15_companies.push_front(13, 7.97); // Warner Bros
    Top_15_companies.push_front(14, 38.71); // Mircochip
    Top_15_companies.push_front(15, 49.78); // The Trade Desk

    // Sorts the Top_15_companies list by the company rank.
    Top_15_companies.selection_sort();

    // Prints the Top_15_companies list.
    std::cout << "Top 15 Companies(Company rank by total Market Capitalization, Stock price): " << std::endl;
    Top_15_companies.print();

    // Gets the sum of the stock prices.
    double sum_of_stock_prices = sum(Top_15_companies);

    // Gets the cost to buy 3 shares of each company.
    double cost_to_buy_all_stocks_3X = sum_of_stock_prices * 3;

    std::cout << "Cost to buy 3 shares of each company: " << cost_to_buy_all_stocks_3X << std::endl;

    return 0;
}