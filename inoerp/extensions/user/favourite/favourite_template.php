<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="user_favouriteId">
      <!--    START OF FORM HEADER-->
      <div id ="form_header">
       <div class="error"></div><div id="loading"></div>
       <div class="show_loading_small"></div>
       <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
       <!--    End of place for showing error messages-->
       <span class="heading">User Favourite </span>
       <div class="large_shadow_box">
        <ul class="column four_column">
         <li><label> User Name: </label><?php echo $f->text_field_ap( array('name' => 'username', 'value' => $user->username, 'readonly' => 1)); ?></li>
         <li><label> First Name: </label><?php echo $f->text_field_ap( array('name' => 'first_name', 'value' => $user->first_name, 'readonly' => 1)); ?></li>
         <li><label> Last Name: </label><?php echo $f->text_field_ap( array('name' => 'last_name', 'value' => $user->last_name, 'readonly' => 1)); ?></li>
        </ul>
       </div>
      </div>
      <form action=""  method="post" id="user_favourite"  name="user_favourite">
       <!--END OF FORM HEADER-->
       <div id ="form_line" class="user_favourite"><span class="heading">Favourite Links</span>
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Details </a></li>
         </ul>
         <div class="tabContainer"> 
          <div id="tabsLine-1" class="tabContent">
           <table class="form_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Id</th>
              <th>Path</th>
              <th>External Link</th>
              <th>Name </th>
              <th>Priority</th>
              <th>Group</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody user_favourite_values" >
             <?php
              $f = new inoform();
              $count = 0;
              foreach ($user_favourite_object as $user_favourite) {
               ?>         
               <tr class="user_favourite_line<?php echo $count ?>">
                <td>    
                 <ul class="inline_action">
                  <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                  <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                  <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->user_favourite_id); ?>"></li>           
                  <li><?php echo $f->hidden_field_withCLass('user_id', $user->user_id,'copyData'); ?></li>
                 </ul>
                </td>
                <td><?php $f->text_field_widsr('user_favourite_id') ?></td>
                <td><?php echo $f->select_field_from_object('path_id', path::find_all(), 'path_id', array('module_code','name'), $$class->path_id, '', 'large', '','',1); ?></td>
                <td><?php $f->text_field_widlr('external_link') ?></td>
                <td><?php $f->text_field_widl('fav_name') ?></td>
                <td><?php echo $f->select_field_from_array('priority', dbObject::$position_array,  $$class->priority); ?></td>
                <td><?php echo $f->select_field_from_object('fav_group', user_favourite::favourite_group(),'option_line_code', 'option_line_value', $$class->fav_group); ?></td>
               </tr>
               <?php
               $count = $count + 1;
              }
             ?>
            </tbody>
           </table>
          </div>
         </div>

        </div>
       </div> 
      </form>
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
