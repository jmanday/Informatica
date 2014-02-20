//package practica2;
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.rmi.*;
import java.util.ArrayList;

/**
 *
 * @author jesus
 */
public interface ServidorInterface extends Remote {
    
    /*
     * Este metodo asigna el testigo al proceso correspondiente.
     */
    public void asignarTestigo(int ind) throws java.rmi.RemoteException;
    
    /*
     * Este metodo remoto conecta a un usuario al char.
     */
    public void conectarse(ProcesoInterface p) throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo remoto devuelve la lista de usuarios conectados.
     */
    public void solicitarTestigo(int ind) throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo remoto devuelve la lista de mensajes que se han escrito en el chat
     */
   // public ArrayList<mensaje> getlistaMensajes() throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo remoto devuelve un objeto ClienteInterface pasandole el nombre como parametro
     */
   // public ClienteInterface obtenerCliente(String nombre) throws  java.rmi.RemoteException;
            
    /*
     * Este metodo remoto nos elimina al cliente de la lista una vez que se desconecte del sistema
     */
   // public void desconectarse(String nomUsuario) throws java.rmi.RemoteException;
}
