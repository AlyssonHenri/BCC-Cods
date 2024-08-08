package db.entities.dao;


import db.DB;
import db.entities.dao.impl.departamentoDaoJDBC;
import db.entities.departamento;

import java.util.List;

public class daoFactory {
    public static DepartamentoDao createDepartamentoDao(){
        return new departamentoDaoJDBC(DB.getConnection());
    }
}
