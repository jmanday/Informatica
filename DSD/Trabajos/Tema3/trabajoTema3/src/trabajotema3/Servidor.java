

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

/**
 *
 * @author jesus
 */
/**
 * Esta clase representa al sirviente de un objeto distribuido de la clase
 * Chat, que implementa la interfaz remota DiaDelaFechaInterfaz.
 */
public class Servidor extends UnicastRemoteObject implements ServidorInterface {
    
    
    private ArrayList<ProcesoInterface> procesos = new ArrayList<ProcesoInterface>();
    private ProcesoInterface proc;    
    private ArrayList<ProcesoInterface> peticiones = new ArrayList<ProcesoInterface>();
    String host;
    
    
    public Servidor(String h) throws RemoteException{
        host = h;
        inicializar_RMI();        
    }
    
    
    public void asignarTestigo(int ind) throws RemoteException{
        int i;
        
        for(i = 0; i < procesos.size(); i++){
            if(i == ind){
                procesos.get(i).asignarTestigo();                 
                proc = procesos.get(i);            
                
            }
            else
                procesos.get(i).posesionTestigo(procesos.get(ind));
        }
    }
    
    
    public void solicitarTestigo(int ind) throws RemoteException{
        if(proc != null){
            peticiones.add(procesos.get(ind));
            
            /* Comprueba si ya ha transcurrido el tiempo del proceso en su sección crítica */
            if(proc.getTime() > proc.getSC()){ // si es así, el testigo pasa a uno de los procesos que hicieron la petición en su momento
                proc.desasignarTestigo();
                proc = null;
                asignarTestigo(0);
                proc.actualizarTestigo(peticiones.get(0));
                peticiones.remove(0);
            }
        }
        else
            proc = procesos.get(ind);
            
    }
    
    
    public void conectarse(ProcesoInterface p) throws RemoteException{
        
        procesos.add(p);
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
    
