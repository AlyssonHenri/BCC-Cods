package db.entities.dao;

import db.entities.departamento;

import java.util.List;

public interface DepartamentoDao {
    void  inserir (departamento d);
    void atualizar (departamento d);
    void deletarPorId (departamento d);
    departamento procurarPorId (int id);
    List<departamento> procurarTodos();
}
