#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <conio.h>
double sum(double x, double y)
{
    return x + y;
}
double dif(double x, double y)
{
    return x - y;
}
double divv(double x, double y)
{
    return x / y;
}
double cot(double x)
{
    return pow(tan(x), -1);
}
double acot(double x)
{
    return (M_PI / 2) - atan(x);
}
double coth(double x)
{
    return pow(tanh(x), -1);
}
int main()
{
    const double m_pi = (double)M_PI;
    double (*MathFunctionsSingle[18])(double) = {sin, cos, tan, cot, asin, acos, atan, acot, sinh, cosh, tanh, coth, sqrt, ceil, fabs, floor, log,  log10};
    double (*MathFunctionsDouble[4])(double, double) = {sum, dif, divv, pow};
    char Character;
    int Answear = -1, PiAnswear, BuildAnswer = -1, BuildAnswerFinal = -1;
    double Number1, Number2, DesiredNumber = 1, BuildNumber;
    printf("Welcome!\nThis is a complex calculator who can help you with basic operations such as the sum of two numbers,\nto a more complex ones like trigonometric functions.\n");
    printf("For more interesting projects you can visit my profile : https://github.com/SorinAlexB\n");
    printf("The actual calculator will start after you press ENTER\n");
    while(1)
    {
        scanf("%c", &Character);
        if(Character == '\n')
        {
            while(Answear != 23)
            {
                system("cls");
                printf("Now you will choose a number to indicate what you wish to do\n");
                printf("1 . sum\t\t2 . dif\t\t3 . div\t\t4 . pow\n5 . sin\t\t6 . cos\t\t7 . tan\t\t8 . cot\n");
                printf("9 . asin\t10. acos\t11. atan\t12. acot\n13. sinh\t14. cosh\t15. tanh\t16. coth\n");
                printf("17. sqrt\t18. ceil\t19. fabs\t20. floor\n21. log\t\t22. log10\t23. exit\n");
                printf("\nYour number (operation) is : ");
                scanf("%d", &Answear);
                system("cls");
                if(Answear >= 1 && Answear <= 4)
                {
                    printf("Enter two numbers.\nYour numbers are : ");
                    scanf("%lf %lf", &Number1, &Number2);
                    printf("The result is : %.4lf\n", (*MathFunctionsDouble[Answear - 1])(Number1, Number2));
                    printf("Press any key to continue\n");
                    getch();
                    scanf("%c", &Character);
                }
                else if(Answear >= 5 && Answear <=  8)
                {
                    printf("Enter one number.\nYour number is : ");
                    scanf("%lf", &Number1);
                    while(Number1 >= 360)
                        Number1 -= 360;
                    Number1 *= ( m_pi / 180.0);
                    printf("The result is : %.4lf\n", (*MathFunctionsSingle[Answear - 5])(Number1));
                    printf("Press any key to continue\n");
                    getch();
                    scanf("%c", &Character);
                }
                else if(Answear >= 9 && Answear <= 12)
                {
                    printf("Please choose if you want to use Pi in your number or not :\n1. Yes\t\t2. No\n");
                    printf("Your answer is : ");
                    scanf("%d", &PiAnswear);
                    system("cls");
                    if(PiAnswear == 2)
                    {
                        printf("Enter one number.\nYour number is : ");
                        scanf("%lf", &Number1);
                        printf("The result is : %.4lf\n", (180 * (*MathFunctionsSingle[Answear - 5])(Number1) / m_pi));
                        printf("Press any key to continue\n");
                        getch();
                        scanf("%c", &Character);
                    }
                    else if(PiAnswear == 1)
                    {
                        DesiredNumber = 1;
                        BuildAnswerFinal = -1;
                        BuildAnswer = -1;
                        while(BuildAnswer != 5)
                        {
                            printf("Your current number is : Pi * DesiredNumber (which currently is %lf)\n", DesiredNumber);
                            printf("You can form the DesiredNumber with the operations :\n1. (+)\t\t2. (-)\t\t3. (*)\t\t4. (:)\n5. Finish form (DesiredNumber is completed)\n");
                            printf("Your choice is : ");
                            scanf("%d", &BuildAnswer);
                            printf("Press any key to continue\n");
                            getch();
                            scanf("%c", &Character);
                            system("cls");
                            if(BuildAnswer != 5 )
                            {
                                switch (BuildAnswer)
                                {
                                case 1:
                                    printf("Choose a number for operation : "), scanf("%lf", &BuildNumber), DesiredNumber += BuildNumber;
                                    break;
                                case 2:
                                    printf("Choose a number for operation : "), scanf("%lf", &BuildNumber), DesiredNumber -= BuildNumber;
                                    break;
                                case 3:
                                    printf("Choose a number for operation : "), scanf("%lf", &BuildNumber), DesiredNumber *= BuildNumber;
                                    break;
                                case 4:
                                    printf("Choose a number for operation : "), scanf("%lf", &BuildNumber), DesiredNumber /= BuildNumber;
                                    break;
                                }
                                printf("The current value of DesireNumber is : %lf\nPress any key to continue\n", DesiredNumber);
                                getch();
                                scanf("%c", &Character);
                                system("cls");
                            }
                            else
                            {
                                DesiredNumber *= m_pi;
                                while(BuildAnswerFinal != 5)
                                {
                                    printf("Now you can modify the entire value of Pi * DesiredNumber (which is %.4lf) with one of these operations :\n", DesiredNumber);
                                    printf("1. (+)\t\t2. (-)\t\t3. (*)\t\t4. (:)\n5. View the final result\n");
                                    printf("Your answer is : ");
                                    scanf("%d",&BuildAnswerFinal);
                                    printf("Press any key to continue\n");
                                    getch();
                                    scanf("%c", &Character);
                                    system("cls");
                                    switch (BuildAnswerFinal)
                                    {
                                    case 1:
                                        printf("Choose a number for operation : "),scanf("%lf", &BuildNumber),DesiredNumber += BuildNumber;
                                        break;
                                    case 2:
                                        printf("Choose a number for operation : "),scanf("%lf", &BuildNumber),DesiredNumber -= BuildNumber;
                                        break;
                                    case 3:
                                        printf("Choose a number for operation : "),scanf("%lf", &BuildNumber),DesiredNumber *= BuildNumber;
                                        break;
                                    case 4:
                                        printf("Choose a number for operation : "),scanf("%lf", &BuildNumber),DesiredNumber /= BuildNumber;
                                        break;
                                    }
                                    printf("The current expression is Pi * DesireNumber = %lf\nPress any key to see the final value\n", DesiredNumber);
                                    scanf("%c", &Character);
                                    system("cls");
                                }
                                printf("The final result is : %.4lf\n", (180 * (*MathFunctionsSingle[Answear - 5])(DesiredNumber) / m_pi) );
                                printf("Press any key to continue\n");
                                scanf("%c", &Character);
                            }
                        }
                    }
                }
                else if(Answear >= 13 && Answear <= 22)
                {
                    printf("Enter one number.\nYour number is : ");
                    scanf("%lf", &Number1);
                    printf("The result is : %.4lf\n", (*MathFunctionsSingle[Answear - 5])(Number1));
                    printf("Press any key to continue\n");
                    getch();
                    scanf("%c", &Character);
                }
                else if(Answear == 23)
                    return 0;
                else if(Answear <= 1 || Answear >= 23)
                {
                    printf("!WRONG NUMBER!\t\t-PLEASE ENTER A VALUE BETWEEN 1 AND 23-\t\t!WRONG NUMBER!\n");
                    printf("Press any key to continue\n");
                    getch();
                    scanf("%c", &Character);
                }
            }
        }
    }
}
