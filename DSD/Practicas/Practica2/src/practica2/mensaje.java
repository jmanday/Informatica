/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package practica2;

import java.io.Serializable;
import java.rmi.server.UnicastRemoteObject;

/**
 *
 * @author jesus
 */
public class mensaje implements Serializable{
    
    private String usuario;
    private String sms;
    
    
    public mensaje(String usu, String mm){
        usuario = usu;
        sms = mm;
    }
    
    public String getNombreUsuario(){
        return usuario;
    }
    
    public String getMensajeUsuario(){
        return sms;
    }
    
}
