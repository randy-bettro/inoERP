<?php

class hr_employee extends dbObject {

 public static $table_name = "hr_employee";
 public static $primary_column = "hr_employee_id";
 public static $key_column = 'last_name';
 public static $dependent_classes = ['hr_employee_education', 'hr_employee_experience', 'hr_employee_termination'];
 public static $module = "hr";
 public static $source_type_a = [
  'MANUAL' => 'Manual',
  'IMPORT' => 'Import'
 ];
 public $field_a = [
  'hr_employee_id',
  'identification_id',
  'identification_type',
  'citizen_number',
  'first_name',
  'last_name',
  'phone',
  'email',
  'language',
  'title',
  'gender',
  'person_type',
  'date_of_birth',
  'city_of_birth',
  'country_of_birth',
  'nationality',
  'disability_code',
  'marital_status',
  'degree',
  'highest_education',
  'education_details',
  'no_of_children',
  'home_address_id',
  'home_address',
  'permanent_address',
  'permanent_address_id',
  'mobile_number',
  'home_phone_number',
  'other_email',
  'date_first_hired',
  'org_id',
  'job_id',
  'position_id',
  'grade_id',
  'payroll_id',
  'location_id',
  'job_type',
  'supervisor_employee_id',
  'probation_period_uom',
  'probation_period',
  'notice_period_uom',
  'notice_period',
  'revision_enabled',
  'status',
  'revision_number',
  'work_policy_id',
  'tax_reg_number',
  'social_ac_no',
  'social_ac_no2',
  'expense_ac_id',
  'salary_ac_id',
  'bank_account_id',
  'performance_id',
  'vehicle_number',
  'asset_numbers',
  'contract_id',
  'passport_number',
  'ledger_id',
  'created_by',
  'creation_date',
  'last_update_by',
  'last_update_date',
 ];
 public $initial_search = [
  'hr_employee_id',
  'identification_id',
  'citizen_number',
  'first_name',
  'last_name',
 ];
 public $column = [
  'hr_employee_id',
  'identification_id',
  'identification_type',
  'citizen_number',
  'first_name',
  'last_name',
 ];
 public $fields_inForm_notInDataBase = [
  "supervisor_employee_name"
 ];
 public $requiredField = [
  'identification_id',
  'identification_type',
  'first_name',
  'last_name',
  'email',
  'person_type',
 ];
 public $hr_employee_id;
 public $identification_id;
 public $identification_type;
 public $citizen_number;
 public $first_name;
 public $last_name;
 public $phone;
 public $email;
 public $language;
 public $title;
 public $gender;
 public $person_type;
 public $date_of_birth;
 public $city_of_birth;
 public $country_of_birth;
 public $nationality;
 public $disability_code;
 public $marital_status;
 public $degree;
 public $highest_education;
 public $education_details;
 public $no_of_children;
 public $home_address_id;
 public $home_address;
 public $permanent_address;
 public $permanent_address_id;
 public $mobile_number;
 public $home_phone_number;
 public $other_email;
 public $date_first_hired;
 public $org_id;
 public $job_id;
 public $position_id;
 public $grade_id;
 public $payroll_id;
 public $location_id;
 public $job_type;
 public $supervisor_employee_id;
 public $probation_period_uom;
 public $probation_period;
 public $notice_period_uom;
 public $notice_period;
 public $revision_enabled;
 public $status;
 public $revision_number;
 public $work_policy_id;
 public $expense_ac_id;
 public $salary_ac_id;
 public $performance_id;
 public $vehicle_number;
 public $asset_numbers;
 public $contract_id;
 public $bank_account_id;
 public $tax_reg_number;
 public $social_ac_no;
 public $social_ac_no2;
 public $passport_number;
 public $ledger_id;
 public $created_by;
 public $creation_date;
 public $last_update_by;
 public $last_update_date;
 public $supervisor_employee_name;
 public $search = [
  '_show_update_path' => 1,
  '_update_action_meassge' => 'Update',
  '_show_view_path' => 1,
 ];
 public $pageTitle = " HR Employee  "; //page Title

 Public static function marital_status() {
  $option_header = option_header::find_by_name('HR_MARITAL_STATUS');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function person_type() {
  $option_header = option_header::find_by_name('HR_PERSON_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function identification_type() {
  $option_header = option_header::find_by_name('HR_IDENTIFICATION_TYPE');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 Public static function gender() {
  $option_header = option_header::find_by_name('HR_GENDER');
  $ol = new option_line();
  $option_lines = $ol->findBy_parentId($option_header->option_header_id);
  return $option_lines;
 }

 public static function find_all_header_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'HEADER' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_all_line_levels() {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE level = 'LINE' ";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_transactionClass($class) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE type_class = '{$class}' AND status='active'";
  $result = self::find_by_sql($sql);
  return $result;
 }

 public static function find_by_payrollId($payroll_id) {
  $sql = " SELECT * FROM ";
  $sql .= self::$table_name;
  $sql .= " WHERE payroll_id = '{$payroll_id}' AND status='active'";
  $result = self::find_by_sql($sql);
  return !empty($result) ? $result : false;
 }

 public static function find_by_userId($user_id) {
  $sql = " SELECT * 
            FROM hr_employee hre, 
                 user 
            WHERE user.hr_employee_id = hre.hr_employee_id
            AND user.user_id = '{$user_id}' LIMIT 1";
  $result = self::find_by_sql($sql);
  return !empty($result) ? array_pop($result) : false;
 }

 public function _before_showing() {
  if (!empty($this->supervisor_employee_id)) {
   $emp_details = hr_employee::find_by_id($this->supervisor_employee_id);
   $this->supervisor_employee_name = $emp_details->first_name . ' ' . $emp_details->last_name;
  }
 }

 public function _after_save() {
//   pa($this);
//   pa($_POST);
  if (!empty($this->hr_employee_id) && !empty($_POST['degree_name']) && !empty($_POST['education_line_id_cb'])) {
   $eedu = new hr_employee_education();
   foreach ($_POST['education_line_id_cb'] as $key => $val) {
    if (empty($val)) {
     continue;
    }
    foreach ($eedu->field_a as $field_k => $field_v) {
     $eedu->$field_v = isset($_POST[$field_v][$key]) ? $_POST[$field_v][$key] : null;
    }
    $eedu->audit_trial();
    $eedu->save();
    unset($eedu);
   }
  }

  if (!empty($this->hr_employee_id) && !empty($_POST['organization_name']) && !empty($_POST['experience_line_id_cb'])) {
   $emp_exp = new hr_employee_experience();
   foreach ($_POST['experience_line_id_cb'] as $key => $val) {
    if (empty($val)) {
     continue;
    }
    foreach ($emp_exp->field_a as $field_k => $field_v) {
     $emp_exp->$field_v = isset($_POST[$field_v][$key]) ? $_POST[$field_v][$key] : null;
    }
    $emp_exp->audit_trial();
    $emp_exp->save();
    unset($emp_exp);
   }
  }
 }

}

//end of hr_employee class
?>