<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="structure">
     <div id="bom_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php
      echo (!empty($show_message)) ? $show_message : "";
      $f = new inoform();
      ?> 
      <!--    End of place for showing error messages-->
      <div id ="form_header">
       <form action=""  method="post" id="hr_team_header"  name="hr_team_header"><span class="heading">HR Team </span>
        <div id="tabsHeader">
         <ul class="tabMain">
          <li><a href="#tabsHeader-1">Basic Info</a></li>
          <li><a href="#tabsHeader-2">Objective</a></li>
          <li><a href="#tabsHeader-3">Notes</a></li>
          <li><a href="#tabsHeader-4">Attachments</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsHeader-1" class="tabContent">
           <div class="large_shadow_box"> 
            <ul class="column header_field">
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="hr_team_header_id select_popup clickable">
               Header Id</label><?php $f->text_field_dsr('hr_team_header_id') ?>
              <a name="show" href="form.php?class_name=hr_team_header_id" class="show hr_team_header_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
             </li>
             <li><label>Type</label><?php echo $f->select_field_from_array('type', hr_team_header::$type_a, $$class->type, 'type','',1,$type_r,$type_r); ?> </li>
             <li><label>Team Name</label><?php $f->text_field_d('team_name'); ?> </li>
             <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_employee_name select_popup clickable">
               Team Lead</label><?php $f->text_field_d('lead_employee_name'); ?>
              <?php echo $f->hidden_field_withId('team_lead_employee_id', $$class->team_lead_employee_id); ?>
             </li>
             <li><label>Region</label><?php echo $f->select_field_from_object('region', hr_team_header::team_region(), 'option_line_code', 'option_line_value', $$class->region, 'region'); ?> </li>
             <li><label>email</label><?php $f->text_field_d('email'); ?> </li>
             <li><label>Status</label><?php $f->status_field_d('status'); ?> </li>
             <li><label>Start Date</label><?php echo $f->date_fieldAnyDay('start_date', $$class->end_date); ?></li>
             <li><label>End Date</label><?php echo $f->date_fieldFromToday('end_date', $$class->end_date); ?></li>
            </ul>
           </div>
          </div>
          <div id="tabsHeader-2" class="tabContent">
           <div><?php
            echo $f->text_area_ap(array('name' => 'objective', 'value' => $$class->objective,
             'row_size' => '10', 'column_size' => '90'));
            ?></div>
          </div>
          <div id="tabsHeader-3" class="tabContent">
           <div> 
            <div id="comments">
             <div id="comment_list">
              <?php echo!(empty($comments)) ? $comments : ""; ?>
             </div>
             <div id ="display_comment_form">
              <?php
              $reference_table = 'hr_team_header';
              $reference_id = $$class->hr_team_header_id;
              ?>
             </div>
             <div id="new_comment">
             </div>
            </div>
           </div>
          </div>
          <div id="tabsHeader-4" class="tabContent">
           <div> <?php echo ino_attachement($file) ?> </div>
          </div>
         </div>
        </div>
       </form>
      </div>

      <div id="form_line" class="form_line"><span class="heading">Team Members </span>
       <form action=""  method="post" id="hr_team_line"  name="hr_team_line">
        <div id="tabsLine">
         <ul class="tabMain">
          <li><a href="#tabsLine-1">Main</a></li>
         </ul>
         <div class="tabContainer">
          <div id="tabsLine-1" class="tabContent">
           <table class="form_line_data_table">
            <thead> 
             <tr>
              <th>Action</th>
              <th>Line Id</th>
              <th>Member Name</th>
              <th>Region</th>
              <th>Role</th>
              <th>Responsibility</th>
              <th>Start Date</th>
              <th>End Date</th>
              <th>Objective</th>
             </tr>
            </thead>
            <tbody class="form_data_line_tbody">
             <?php
             $count = 0;
             foreach ($hr_team_line_object as $hr_team_line) {
              if (!empty($hr_team_line->member_employee_id)) {
               $emp_details_l = hr_employee::find_by_id($hr_team_line->member_employee_id);
               $hr_team_line->member_employee_name = $emp_details_l->first_name . ' ' . $emp_details_l->last_name;
              }
              ?>         
              <tr class="hr_team_line<?php echo $count ?>">
               <td>    
                <ul class="inline_action">
                 <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                 <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                 <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class_second->hr_team_line_id); ?>"></li>           
                 <li><?php echo form::hidden_field('hr_team_header_id', $hr_team_header->hr_team_header_id); ?></li>
                </ul>
               </td>
               <td><?php $f->text_field_wid2sr('hr_team_line_id'); ?></td>
               <td><?php
                $f->text_field_wid2('member_employee_name', 'select employee');
                echo $f->hidden_field('member_employee_id', $$class_second->member_employee_id);
                ?><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="select_employee_name select_popup clickable"></td>
               <td><?php echo $f->select_field_from_object('region', sys_value_group_line::find_by_parent_id($team_reg_vg_id), 'sys_value_group_line_id', 'code_value', $$class_second->region); ?></td>
               <td><?php echo $f->select_field_from_object('role', hr_team_header::hr_role(), 'option_line_code', 'option_line_value', $$class_second->role); ?></td>
               <td><?php echo $f->select_field_from_array('responsibility', hr_team_line::$responsibility_a, $$class_second->responsibility); ?></td>
               <td><?php echo $f->date_fieldFromToday('start_date', $$class_second->start_date); ?></td>
               <td><?php echo $f->date_fieldFromToday('end_date', $$class_second->end_date); ?></td>
               <td><?php $f->text_field_wid2l('objective'); ?></td>
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
       </form>
      </div>

      <!--END OF FORM HEADER-->
     </div>
    </div>
    <!--   end of structure-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="hr_team_header" ></li>
  <li class="lineClassName" data-lineClassName="hr_team_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="hr_team_header_id" ></li>
  <li class="form_header_id" data-form_header_id="hr_team_header" ></li>
  <li class="line_key_field" data-line_key_field="position_id" ></li>
  <li class="single_line" data-single_line="true" ></li>
  <li class="form_line_id" data-form_line_id="hr_team_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="hr_team_header_id" ></li>
  <li class="btn1DivId" data-btn1DivId="hr_team_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
 </ul>
</div>

<?php include_template('footer.inc') ?>
