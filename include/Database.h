/**
 * @file Database.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Database.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Admin.h"

#ifndef DATABASE_H 
#define	DATABASE_H 

class Database{
  public:
    Database(); /* basic constructor */
    ~Database();
    /**
     * @brief adds a new user to the database
     * 
     */
    void addUser(User);
    /**
     * @brief Get the User object in the database, if not throws an exception
     * 
     * @param employeeNumber 
     * @param NIF 
     * @return User 
     */
    User getUser(std::string employeeNumber,std::string NIF);
  private:
    std::vector<User> user;
};

#endif