/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jesus
 */
public class Proceso extends UnicastRemoteObject implements ProcesoInterface{
    private String nom_proc;
    private int id;
    private double tiempo_sc;
    private algoritmoDistribuido d;
    Tiempo tmp = new Tiempo();
    private boolean testigo = false;
    private ProcesoInterface proc_poseedor_testigo;
    
    
    public Proceso(int ident, algoritmoDistribuido alg) throws RemoteException{
        d = alg;
        id = ident;
        tiempo_sc = (Math.random()*1+2);
        testigo = false;
        inicializar_RMI();
    }
    
    
    public boolean tieneTestigo() throws RemoteException{
        return testigo;
    }
    
    
    public void asignarTestigo() throws RemoteException{
        testigo = true;
        
        /* Tiempo que tardará el proceso en su seccion critica */        
        tmp.Contar();
    }
    
    
    public void actualizarTestigo(ProcesoInterface p) throws RemoteException{
        d.actualizarTestigo(p);
    }
    
    
    public int getTime(){
        return tmp.getSegundos();
    }
    
    
    public void desasignarTestigo() throws RemoteException{
        testigo = false;
    }
    
    
    public void posesionTestigo(ProcesoInterface proc) throws RemoteException{
        proc_poseedor_testigo = proc;
    }
    
    
    public String getNombre() throws RemoteException{
        return nom_proc;
    }
    
    
    public int getID() throws RemoteException{
        return id;
    }
    
    
    public double getSC() throws RemoteException{
        return tiempo_sc;
    }
       
    
    private void inicializar_RMI() throws RemoteException
    {
       
        int i = id + 1;
	try 
	{    	
		//Le indicamos al sistema donde buscar los stubs 
		System.setProperty ("java.rmi.server.codebase", "file:./");		    
		System.out.println("proceso" + i + " registrado.");
	} 
	catch (Exception e) 
	{ 
		System.out.println("Exception: " + e.getMessage());
		e.printStackTrace();
	}
	 
        
        
	try 
	{
		//registra la clase en el servicio de nombres de RMI
                String nomb = "rmi://localhost/proceso" + i;
		Naming.rebind(nomb, this);
	} 
	catch (MalformedURLException e) 
	{
		e.printStackTrace();
	}         
        
    }    
    
      
}
