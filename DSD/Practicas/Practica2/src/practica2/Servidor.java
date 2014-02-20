//package practica2;
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.logging.Level;
import java.util.logging.Logger;
import practica2.mensaje;

/**
 *
 * @author jesus
 */
/**
 * Esta clase representa al sirviente de un objeto distribuido de la clase
 * Chat, que implementa la interfaz remota DiaDelaFechaInterfaz.
 */
public class Servidor extends UnicastRemoteObject implements ServidorInterface {
    
    private ArrayList<ClienteInterface> usuarios = new ArrayList<ClienteInterface>();
    private ArrayList<mensaje> listamensajes = new ArrayList<mensaje>();
    private HashMap<String,ArrayList<mensaje>> historialMensajes = new HashMap<String,ArrayList<mensaje>>(); 
    private String ultimo_sms;
    String host;
    
    public Servidor(String h) throws RemoteException{
        host = h;
        inicializar_RMI();        
    }
    
    
    public void enviarMensaje(ClienteInterface usuario, String sms) throws RemoteException{
        mensaje m = new mensaje(usuario.getNombre(), sms);
        listamensajes.add(m);
        try{
            for(int i = 0; i < usuarios.size(); i++){
                usuarios.get(i).difundirMensaje(m);
            }
        } catch (Exception e) 
	{ 
		System.out.println("El cliente cerro la sesion");
		 
        }
    }
    
    
    public ClienteInterface obtenerCliente(String nombre) throws RemoteException{
        for(int i = 0; i < usuarios.size(); i++)
            if(usuarios.get(i).getNombre().equals(nombre))
                return usuarios.get(i);
        
        return null;
    }
    
    
    public void desconectarse(String nomUsuario) throws RemoteException {
        for(int i = 0; i < usuarios.size(); i++){
            if(usuarios.get(i).getNombre().equals(nomUsuario))
                usuarios.remove(i);
        }
        
        for(int j = 0; j < usuarios.size(); j++)
                usuarios.get(j).actualizarConectados(usuarios);
    }
    
    
    public boolean conectarse(ClienteInterface usuario) throws RemoteException{
        
        if(existeUsuario(usuario) == true)
            return false;
        else{            
            usuarios.add(usuario);
            for(int i = 0; i < usuarios.size(); i++)
                usuarios.get(i).actualizarConectados(usuarios);
            return true;
        }
    }
    
    
    public boolean existeUsuario(ClienteInterface usu) throws RemoteException{
        
        for(int i = 0; i < usuarios.size(); i++){
            if(usuarios.get(i).getNombre().equals(usu.getNombre()))
                return true;
        }
        
        return false;
    }
    
    
    @Override
    public ArrayList<ClienteInterface> getlistaUsuarios() throws RemoteException{
        return usuarios;
    }
    
    
    public ArrayList<mensaje> getlistaMensajes() throws RemoteException{
        return listamensajes;
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
		Naming.rebind("rmi://"+host+"/servidor", this);
	} 
	catch (MalformedURLException e) 
	{
		e.printStackTrace();
	} 
    }
    
    
    public static void main(String args[]) {
        
        String host = "localhost";
        
        try 
	{                
		new Servidor(host);

 
        System.out.println("\nEl servidor esta andando.");
	} 
	catch (RemoteException e) 
	{
		e.printStackTrace();
	}
        
    } // end main    
}
    
