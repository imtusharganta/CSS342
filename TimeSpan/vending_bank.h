#ifndef VENDINGBANK_H_
#define VENDINGBANK_H_

#pragma once

class VendingBank
{
public:
    // constructors
    VendingBank();
    VendingBank(int id);
    VendingBank(int id, int pennies);
    VendingBank(int id, int pennies, int nickels);
    VendingBank(int id, int pennies, int nickels, int dimes);
    VendingBank(int id, int pennies, int nickels, int dimes, int quarters);

    // Getters
    int id() const;
    int pennies() const;
    int dimes() const;
    int nickels() const;
    int quarters() const;
    double get_total() const;

    // Setters
    void set_pennies(int pennies);
    void set_nickels(int nickels);
    void set_dimes(int dimes);
    void set_quarters(int quarters);
    void set_total(double total);

    // Actions
    VendingBank Add(int pennies) const;
    VendingBank Add(int pennies, int nickels) const;
    VendingBank Add(int pennies, int nickels, int dimes) const;
    VendingBank Add(int pennies, int nickels, int dimes, int quarters) const;
    VendingBank Subtract(int pennies, int nickels, int dimes, int quarters) const;
    VendingBank Subtract(int pennies, int nickels, int dimes) const;
    VendingBank Subtract(int pennies, int nickels) const;
    VendingBank Subtract(int pennies) const;

private:
    int id_;
    int pennies_;
    int nickels_;
    int dimes_;
    int quarters_;
    double total;
};

#endif
