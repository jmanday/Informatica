
import java.awt.Component;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import practica2.mensaje;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
///package practica2;

/**
 *
 * @author jesus
 */
public class chat_privado extends javax.swing.JFrame {

    private ClienteInterface origen;
    private ClienteInterface destino;  
    ArrayList<mensaje> listamensajes;
    private Component confirmation;
    
    /**
     * Creates new form chat_privado
     */
    public chat_privado(ClienteInterface cli1, ClienteInterface cli2) {
        origen = cli1;
        destino = cli2;
        listamensajes = new ArrayList<mensaje>();
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        nombre_amigo = new javax.swing.JLabel();
        mensajes = new javax.swing.JScrollPane();
        mensajes_privado = new javax.swing.JList();
        texto = new javax.swing.JTextField();
        enviar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        mensajes.setViewportView(mensajes_privado);

        enviar.setText("Enviar");
        enviar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                enviarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(167, 167, 167)
                        .addComponent(nombre_amigo))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(51, 51, 51)
                        .addComponent(texto, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(enviar, javax.swing.GroupLayout.PREFERRED_SIZE, 76, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(51, 51, 51)
                        .addComponent(mensajes, javax.swing.GroupLayout.PREFERRED_SIZE, 285, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(64, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addComponent(nombre_amigo)
                .addGap(18, 18, 18)
                .addComponent(mensajes, javax.swing.GroupLayout.DEFAULT_SIZE, 211, Short.MAX_VALUE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(texto, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(enviar))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void enviarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_enviarActionPerformed
        mensaje m = null;
        try {
            // TODO add your handling code here:            
            if(texto.getText().isEmpty() == false){
                m = new mensaje(origen.getNombre(),texto.getText());
                listamensajes.add(m);
                actualizarLista();
                if(destino != null)
                    destino.mensajePrivado(m);                
                texto.setText("");
            }
            else{
                JOptionPane.showMessageDialog(null, "Debe escribir el texto a enviar");
            }
            
        } catch (RemoteException ex) {
            Logger.getLogger(chat_privado.class.getName()).log(Level.SEVERE, null, ex);
        }          
    }//GEN-LAST:event_enviarActionPerformed

    
    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        // TODO add your handling code here:
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); 
      
        Object [] opciones ={"Aceptar","Cancelar"};
        
        int eleccion = JOptionPane.showOptionDialog(confirmation,"¿Desea cerrar la ventana?","Mensaje de Confirmacion",
        JOptionPane.YES_NO_OPTION,
        JOptionPane.QUESTION_MESSAGE,null,opciones,"Cancelar");
        if (eleccion == JOptionPane.YES_OPTION){
            try {
                //serv.desconectarse(nickname.getText());
            } catch (Exception ex) {
                Logger.getLogger(chat.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            dispose();
        }
        else{
            
        }
    }//GEN-LAST:event_formWindowClosing

    
    public void añadirMensaje(mensaje sms){
        listamensajes.add(sms);
        actualizarLista();
    }
    
    
    public void actualizarLista(){          
        DefaultListModel modeloLista = new DefaultListModel();
        
        modeloLista.clear();
        for(int i = 0; i < listamensajes.size(); i++)
            modeloLista.addElement(listamensajes.get(i).getNombreUsuario() + " dijo: " + listamensajes.get(i).getMensajeUsuario());            
                   
        mensajes_privado.setModel(modeloLista);
        mensajes_privado.repaint();
    }
    /**
     * @param args the command line arguments
     */
   
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton enviar;
    private javax.swing.JScrollPane mensajes;
    private javax.swing.JList mensajes_privado;
    private javax.swing.JLabel nombre_amigo;
    private javax.swing.JTextField texto;
    // End of variables declaration//GEN-END:variables
}
