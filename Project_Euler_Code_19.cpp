#include <stdio.h>

int main(void) {
    int monthDays[12] = {
        31, // Jan
        28, // Feb
        31, // Mar
        30, // Apr
        31, // May
        30, // Jun
        31, // Jul
        31, // Aug
        30, // Sep
        31, // Oct
        30, // Nov
        31  // Dec
    };

    int sunCount = 0;
    int month;
    int year;
    int dayofweek = 2; // 1 Jan 1901 was Tuesday; Monday = 1, Sunday = 7

    for (year = 1901; year <= 2000; year++) {
        if ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0)) {
            monthDays[1] = 29;
        } else {
            monthDays[1] = 28;
        }

        for (month = 1; month <= 12; month++) {
            /* The current value represents the first day of this month. */
            if (dayofweek == 7) {
                sunCount++;
            }

            /* Move to the first day of the next month. */
            dayofweek += monthDays[month - 1] % 7;

            if (dayofweek > 7) {
                dayofweek %= 7;

                if (dayofweek == 0) {
                    dayofweek = 7;
                }
            }
        }
    }

    printf("Sun count : %d\n", sunCount);
    return 0;
}
// // Method 2 
// #include <stdio.h>

// int main(void) {
//     int monthDays[12] = {
//         31, 28, 31, 30, 31, 30,
//         31, 31, 30, 31, 30, 31
//     };

//     int sunCount = 0;
//     int dayOfWeek = 1;  // 1 Jan 1900 was Monday; 0 = Sunday

//     for (int year = 1900; year <= 2000; year++) {
//         int leapYear = (year % 400 == 0) ||
//                        (year % 4 == 0 && year % 100 != 0);

//         monthDays[1] = leapYear ? 29 : 28;

//         for (int month = 0; month < 12; month++) {
//             if (year >= 1901 && dayOfWeek == 0) {
//                 sunCount++;
//             }

//             dayOfWeek = (dayOfWeek + monthDays[month]) % 7;
//         }
//     }

//     printf("Sun count: %d\n", sunCount);
//     return 0;
// }
