/**
 * @file Interface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Interface.h"
#include "CLInterface.h"

Interface::Interface(){};

Interface *Interface::Create(const std::string type){
  if (type == "CLI"){
    return new CLInterface;
  }
  else {
    throw std::runtime_error(type + " is not a defined Interface type");
    std::exit(1);
  }
};

void Interface::login(const std::string userNumber, const std::string nif){
  loginInterface = LoginInterface::Create();
  this->loginInterface = loginInterface;
  this->loginInterface->askEmployeeNumber(userNumber);
  this->loginInterface->askNIF(nif);
  if (this->loginInterface->checkUser()){
    system("clear");
    delete this->loginInterface;
  } else {
    exit(1);
  }
};

bool Interface::loadMenu(){
  dashboard = Dashboard::Create();
  this->dashboard = dashboard;
  this->dashboard->setUser(this->loginInterface->getUser());
  this->dashboard->showMainMenu();
  bool canExit = this->dashboard->canExit();
  delete this->dashboard;
  return canExit;
};

Interface::~Interface(){};