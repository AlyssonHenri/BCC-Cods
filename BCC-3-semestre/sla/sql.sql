CREATE OR REPLACE FUNCTION Calcular_Dano (personagem VARCHAR, slot_arma VARCHAR, alvo VARCHAR)
RETURNS TABLE(dano_reduzido VARCHAR, media_dano VARCHAR) AS $$
DECLARE
    dano_fis INT;
    dano_mag INT;
    dano_fog INT;
    dano_ele INT;
    r_fis_monstro INT;
    r_mag_monstro INT;
    r_fog_monstro INT;
    r_ele_monstro INT;
    dano1 INT;
    dano2 INT;
    dano3 INT;
    dano4 INT;
    total INT;
    media FLOAT;
BEGIN
    SELECT fis, magi, fire, eletro INTO dano_fis, dano_mag, dano_fog, dano_ele
    FROM equipamentos a
    JOIN equipa e ON a.nome_equipamento = e.nome_item
    WHERE slot_arma = slot;
    
    SELECT r_fis, r_magic, r_fogo, r_electro INTO r_fis_monstro, r_mag_monstro, r_fog_monstro, r_ele_monstro
    FROM monstro
    WHERE nome_monstro = alvo;

    IF dano_fis > r_fis_monstro AND dano_fis != 0 THEN
        SELECT (dano_fis - 0.79 * r_fis_monstro * POWER(2.71828, (-0.27 * (r_fis_monstro / dano_fis)))) INTO dano1;
    ELSEIF dano_fis < r_fis_monstro AND dano_fis != 0 THEN
        SELECT (0.4 * (POWER(dano_fis, 3) / (POWER(r_fis_monstro, 2)) - 0.09 * (POWER(dano_fis, 2) / r_fis_monstro) + 0.1 * dano_fis)) INTO dano1;
    ELSE 
        SELECT 0 INTO dano1;
    END IF;
    
    IF dano_mag > r_mag_monstro AND dano_mag != 0 THEN
        SELECT (dano_mag - 0.79 * r_mag_monstro * POWER(2.71828, (-0.27 * (r_mag_monstro / dano_mag)))) INTO dano2;
    ELSEIF dano_mag < r_mag_monstro AND dano_mag != 0 THEN
        SELECT (0.4 * (POWER(dano_mag, 3) / (POWER(r_mag_monstro, 2)) - 0.09 * (POWER(dano_mag, 2) / r_mag_monstro) + 0.1 * dano_mag)) INTO dano2;
    ELSE 
        SELECT 0 INTO dano2;    
    END IF;

    IF dano_fog > r_fog_monstro AND dano_fog != 0 THEN
        SELECT (dano_fog - 0.79 * r_fog_monstro * POWER(2.71828, (-0.27 * (r_fog_monstro / dano_fog)))) INTO dano3;
    ELSEIF dano_fog < r_fog_monstro AND dano_fog != 0 THEN
        SELECT (0.4 * (POWER(dano_fog, 3) / (POWER(r_fog_monstro, 2)) - 0.09 * (POWER(dano_fog, 2) / r_fog_monstro) + 0.1 * dano_fog)) INTO dano3;
    ELSE 
        SELECT 0 INTO dano3;      
    END IF;

    IF dano_ele > r_ele_monstro AND dano_ele != 0 THEN
        SELECT (dano_ele - 0.79 * r_ele_monstro * POWER(2.71828, (-0.27 * (r_ele_monstro / dano_ele)))) INTO dano4;
    ELSEIF dano_ele < r_ele_monstro AND dano_ele != 0 THEN
        SELECT (0.4 * (POWER(dano_ele, 3) / (POWER(r_ele_monstro, 2)) - 0.09 * (POWER(dano_ele, 2) / r_ele_monstro) + 0.1 * dano_ele)) INTO dano4;
    ELSE 
        SELECT 0 INTO dano4;      
    END IF;

    SELECT dano1 + dano2 + dano3 + dano4 INTO total;
    
    SELECT total / hp_monstro::FLOAT INTO media
    FROM monstro
    WHERE nome_monstro = alvo;

    RETURN QUERY SELECT 'Dano por hit: ' || total::VARCHAR, media::FLOAT(2)::VARCHAR;
END;
$$ LANGUAGE plpgsql;
