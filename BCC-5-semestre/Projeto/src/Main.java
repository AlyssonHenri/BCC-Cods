import db.entities.dao.daoFactory;
import db.entities.departamento;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
//        departamento d = daoFactory.createDepartamentoDao().procurarPorId(1);
//        System.out.println(d.toString());
//        List<departamento> lista = new ArrayList<>();
//
//        lista = daoFactory.createDepartamentoDao().procurarTodos();
//
//        System.out.println(lista.toString());

        departamento d = new departamento();
        d.setNome("Almoxerifado");

        daoFactory.createDepartamentoDao().inserir(d);

//        departamento d = new departamento();
//        d.setNome("Bombeiros");
//        d.setId(3);
//
//        daoFactory.createDepartamentoDao().atualizar(d);
    }
}