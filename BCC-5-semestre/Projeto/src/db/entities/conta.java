package db.entities;

import java.sql.Time;
import java.util.Date;
import java.util.Objects;

public class conta {
    private int id;
    private String nome;
    private String telefone;
    private String cpf;
    private String endereco;
    private String cargo;
    private float salario;
    private Date data_contrato;
    private String inicio_expediente;
    private String fim_expediente;
    private float mensalidade;
    private int conta_TIPO;
    private String login;
    private String senha;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public Date getData_contrato() {
        return data_contrato;
    }

    public void setData_contrato(Date data_contrato) {
        this.data_contrato = data_contrato;
    }

    public String getInicio_expediente() {
        return inicio_expediente;
    }

    public void setInicio_expediente(String inicio_expediente) {
        this.inicio_expediente = inicio_expediente;
    }

    public String getFim_expediente() {
        return fim_expediente;
    }

    public void setFim_expediente(String fim_expediente) {
        this.fim_expediente = fim_expediente;
    }

    public float getMensalidade() {
        return mensalidade;
    }

    public void setMensalidade(float mensalidade) {
        this.mensalidade = mensalidade;
    }

    public int getConta_TIPO() {
        return conta_TIPO;
    }

    public void setConta_TIPO(int conta_TIPO) {
        this.conta_TIPO = conta_TIPO;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        conta conta = (conta) o;
        return getId() == conta.getId() && Float.compare(conta.getSalario(), getSalario()) == 0 && Float.compare(conta.getMensalidade(), getMensalidade()) == 0 && getConta_TIPO() == conta.getConta_TIPO() && Objects.equals(getNome(), conta.getNome()) && Objects.equals(getTelefone(), conta.getTelefone()) && Objects.equals(getCpf(), conta.getCpf()) && Objects.equals(getEndereco(), conta.getEndereco()) && Objects.equals(getCargo(), conta.getCargo()) && Objects.equals(getData_contrato(), conta.getData_contrato()) && Objects.equals(getInicio_expediente(), conta.getInicio_expediente()) && Objects.equals(getFim_expediente(), conta.getFim_expediente()) && Objects.equals(getLogin(), conta.getLogin()) && Objects.equals(getSenha(), conta.getSenha());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId(), getNome(), getTelefone(), getCpf(), getEndereco(), getCargo(), getSalario(), getData_contrato(), getInicio_expediente(), getFim_expediente(), getMensalidade(), getConta_TIPO(), getLogin(), getSenha());
    }

    @Override
    public String toString() {
        return "conta{" +
                "id=" + id +
                ", nome='" + nome + '\'' +
                ", telefone='" + telefone + '\'' +
                ", cpf='" + cpf + '\'' +
                ", endereco='" + endereco + '\'' +
                ", cargo='" + cargo + '\'' +
                ", salario=" + salario +
                ", data_contrato=" + data_contrato +
                ", inicio_expediente='" + inicio_expediente + '\'' +
                ", fim_expediente='" + fim_expediente + '\'' +
                ", mensalidade=" + mensalidade +
                ", conta_TIPO=" + conta_TIPO +
                ", login='" + login + '\'' +
                ", senha='" + senha + '\'' +
                '}';
    }
}
