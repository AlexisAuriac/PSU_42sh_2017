/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Macros for general errors.
*/

#ifndef ERROR_GENERAL_H
#define ERROR_GENERAL_H

//access
#define ERROR_NOT_FOUND(name)		\
printf("%s: Command not found.\n", name)
#define ERROR_PERMISSON(name)		\
printf("%s: Permission denied.\n", name)
#define ERROR_WRONG_ARCH(path)		\
printf("%s: Exec format error. Wrong Architecture.\n", path)

//system call
#define ERROR_NO_FILE(name)		\
printf("%s: No such file or directory.\n", name)

#endif