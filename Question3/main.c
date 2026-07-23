#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    int fd;
    struct Employee emp[3] = {
        {1, "Rahul", 30000},
        {2, "Priya", 35000},
        {3, "Amit", 40000}
    };

    struct Employee updated = {2, "Priya", 45000};
    struct Employee result;

    /* Create and open the employee file */
    fd = open("employees.dat", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("File open failed");
        return 1;
    }

    /* Write all employee records */
    write(fd, emp, sizeof(emp));
    printf("Employee records written successfully.\n");

    /* Move directly to the second record and update it */
    lseek(fd, sizeof(struct Employee), SEEK_SET);
    write(fd, &updated, sizeof(updated));
    printf("Employee ID 2 updated successfully.\n");

    /* Move again to the second record and read it */
    lseek(fd, sizeof(struct Employee), SEEK_SET);
    read(fd, &result, sizeof(result));

    printf("\nRetrieved employee record:\n");
    printf("ID: %d\n", result.id);
    printf("Name: %s\n", result.name);
    printf("Salary: %.2f\n", result.salary);

    close(fd);

    return 0;
}
