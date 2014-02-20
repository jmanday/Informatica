/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package practica2;

import java.rmi.Remote;
import java.util.ArrayList;
import java.util.HashMap;
import practica2.mensaje;

/**
 *
 * @author jesus
 */
public interface ClienteInterface extends Remote{
    
    /*
     * Este metodo envía mensajes a los cliente conectados
     */
    public void difundirMensaje(mensaje m) throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo devuelve el nombre de un objeto ClienteInterface
     */
    public String getNombre() throws java.rmi.RemoteException;
    
    
    /*
     * Este metodo actualiza para cada Cliente la lista de usuarios que se han conectado
     */
    public void actualizarConectados(ArrayList<ClienteInterface> listaConectados) throws java.rmi.RemoteException;

    
    /*
     * Este metodo remoto avisa al otro usuario de que va a iniciar una sesion privada con el
     */
    public void iniciarSesion(ClienteInterface client) throws java.rmi.RemoteException;

    
    /*
     * Este metodo recibe un mensaje privado
     */
    public void mensajePrivado(mensaje sms) throws java.rmi.RemoteException;
}
