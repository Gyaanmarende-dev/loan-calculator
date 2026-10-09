#include <stdio.h>
#include <math.h>

int main(void) {
    double amount, yearly_rate , monthly_rate;
    double payment, total, balance, interest, principal;
    int months, month;

    printf("Loan amount: ");
    scanf("%lf", &amount);

    printf("Yearly interest rate(%%): ");
    scanf("%lf", &yearly_rate);

    printf("Months to repay: ");
    scanf("%d", &months);

    monthly_rate = yearly_rate/12/100;

    if (monthly_rate == 0) {
        payment = amount/months;
    } else {
        payment = amount * monthly_rate/(1-pow(1 + monthly_rate, -months));
    }
    total = payment * months;

    printf("\nMonthly payment: %.2f\n", payment);
    printf("Total paid back: %.2f\n", total);
    printf("Total interest: %.2f\n\n", total-amount);

    printf("Month | Interest | Principal | Balance\n");
    balance = amount;
    for (month = 1;month <= months; month++) {
        interest = balance * monthly_rate;
        principal = payment - interest;
        balance = balance -principal;
        if(balance < 0) balance = 0;
        printf("%5d | %8.2f | %9.2f | %8.2f\n",month, interest, principal, balance);
    }
    return 0;
}