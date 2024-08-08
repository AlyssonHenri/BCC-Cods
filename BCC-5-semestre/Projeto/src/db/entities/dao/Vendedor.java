package db.entities.dao;

import db.entities.vendedor;

import java.util.List;

public interface Vendedor {

    void inserir (vendedor v);
    void atualizar (vendedor v);
    void deletarPorId(int id);
    vendedor procurarPorId (int id);
    List<vendedor> procurarTodos();
}
