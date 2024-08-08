package db.entities.dao.impl;

import db.DB;
import db.entities.dao.DepartamentoDao;
import db.entities.departamento;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class departamentoDaoJDBC implements DepartamentoDao {

    private Connection conn;

    public departamentoDaoJDBC(Connection conn) {
        this.conn = conn;
    }

    @Override
    public void inserir(departamento d) {
        PreparedStatement st = null;
        try {
            st =  conn.prepareStatement("insert into departamento(nome) values(?)", Statement.RETURN_GENERATED_KEYS);
            st.setString(1,d.getNome());
            int linha = st.executeUpdate();
            if(linha > 0 ){
                ResultSet rs = st.getGeneratedKeys();
                if(rs.next()){
                    d.setId(rs.getInt(1));
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            DB.closeStatment(st);
        }
    }

    @Override
    public void atualizar(departamento d) {
        PreparedStatement st = null;

        try {
            st = conn.prepareStatement("update departamento set nome = ? where id = ?");
            st.setString(1,d.getNome());
            st.setInt(2,d.getId());
            st.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            DB.closeStatment(st);
        }
    }

    @Override
    public void deletarPorId(departamento d) {
        PreparedStatement st = null;

        try {
            st = conn.prepareStatement("remove from departamento where id = ?");
            st.setInt(1,d.getId());
            st.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            DB.closeStatment(st);
        }

    }

    @Override
    public departamento procurarPorId(int id) {
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            st = conn.prepareStatement("select id,nome from departamento where id=?");
            st.setInt(1,id);
            rs = st.executeQuery();
            if (rs.next()){
                departamento d = new departamento();
                d.setId(rs.getInt("id"));
                d.setNome(rs.getString("nome"));
                return d;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            DB.closeResultSet(rs);
            DB.closeStatment(st);
        }
        return null;
    }

    @Override
    public List<departamento> procurarTodos() {
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            st = conn.prepareStatement("select id, nome from departamento");
            rs = st.executeQuery();
            List<departamento> lista = new ArrayList<>();
            while(rs.next()){
                departamento d = new departamento();
                d.setNome(rs.getString("nome"));
                d.setId(rs.getInt("id"));
                lista.add(d);
            }
            return lista;
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            DB.closeResultSet(rs);
            DB.closeStatment(st);
        }

    }
}
