package db.entities.dao.impl;

import db.DB;
import db.entities.conta;
import db.entities.dao.contaDao;

import java.sql.*;
import java.util.List;

public class contaDaoJDBC implements contaDao {
    private Connection conn = null;

    public contaDaoJDBC(Connection conn){this.conn = conn;}

    @Override
    public void inserirCliente(conta c) {

    }

    @Override
    public void inserirFuncionario(conta c) {
        PreparedStatement st = null;
        try {
            st = conn.prepareStatement("insert into conta(nome,telefone,cpf,endereco,cargo,salario,data_contrato,inicio_expediente,fim_expediente,conta_TIPO,login,senha) values(?,?,?,?,?,?,?,?,?,?,?,?)", Statement.RETURN_GENERATED_KEYS);
            st.setString(1, c.getNome());
            st.setString(2,c.getTelefone());
            st.setString(3,c.getCpf());
            st.setString(4,c.getEndereco());
            st.setString(5,c.getCargo());
            st.setFloat(6,c.getSalario());
            st.setDate(7, (Date) c.getData_contrato());
            st.setTime(8, Time.valueOf(c.getInicio_expediente()));
            st.setTime(9, Time.valueOf(c.getFim_expediente()));
            st.setInt(10,c.getConta_TIPO());
            st.setString(11,c.getLogin());
            st.setString(12,c.getSenha());
        } catch (SQLException e){
            throw new RuntimeException(e);
        } finally {
            DB.closeStatment(st);
        }
    }

    @Override
    public void atualizar(conta c) {
        PreparedStatement st = null;

        try {
            st = conn.prepareStatement("");
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            DB.closeStatment(st);
        }
    }

    @Override
    public void deletarPorId(conta c) {

    }

    @Override
    public conta procurarPorId(int id) {
        return null;
    }

    @Override
    public List<conta> procurarTodos() {
        return null;
    }
}
