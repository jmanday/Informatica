/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import practica2.mensaje;

/**
 *
 * @author jesus
 */
public class Cliente extends UnicastRemoteObject implements ClienteInterface{
    private chat c;
    private chat_privado cp;
    private String nom_usuario;
    private ArrayList<mensaje> sms = new ArrayList();
    
    
    public Cliente(String nom, chat nchat) throws RemoteException{
        nom_usuario = nom;
        c = nchat;
        inicializar_RMI();
    }
    
    
    public void difundirMensaje(mensaje m) throws RemoteException{
        sms.add(m);
        c.actualizarMensajes(sms);        
    }
    
    
    public String getNombre() throws RemoteException{
        return nom_usuario;
    }
    
    
    public void actualizarConectados(ArrayList<ClienteInterface> lista){
        try {
            c.actualizarListaConectados(lista);
        } catch (RemoteException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    public void iniciarSesion(ClienteInterface client) throws RemoteException{
        cp = new chat_privado(this,client);
        cp.setTitle(this.getNombre());
        cp.setVisible(true);
    }
    
    
    public void mensajePrivado(mensaje sms) throws RemoteException{
        cp.añadirMensaje(sms);
    }
    
    
    private void inicializar_RMI() throws RemoteException
    {
       
	try 
	{    	
		//Le indicamos al sistema donde buscar los stubs 
		System.setProperty ("java.rmi.server.codebase", "file:./");		    
		System.out.println("Servidor rmi iniciado. Esperando solicitudes");
	} 
	catch (Exception e) 
	{ 
		System.out.println("Exception: " + e.getMessage());
		e.printStackTrace();
	}
	 
        
        
	try 
	{
		//registra la clase en el servicio de nombres de RMI
		Naming.rebind("rmi://localhost/" + nom_usuario, this);
	} 
	catch (MalformedURLException e) 
	{
		e.printStackTrace();
	} 
    }

}
