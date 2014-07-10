// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// The "Vehicle" class

function Vehicle(x,y) {
  this.acceleration = new PVector(0,0);
  this.velocity = new PVector(0,-2);
  this.position = new PVector(x,y);
  this.r = 6;
  this.maxspeed = 4;
  this.maxforce = 0.1;
}

  // Method to update location
Vehicle.prototype.update = function() {
  // Update velocity
  this.velocity.add(this.acceleration);
  // Limit speed
  this.velocity.limit(this.maxspeed);
  this.position.add(this.velocity);
  // Reset accelerationelertion to 0 each cycle
  this.acceleration.mult(0);
}

Vehicle.prototype.applyForce = function(force) {
  // We could add mass here if we want A = F / M
  this.acceleration.add(force);
}

// A method that calculates a steering force towards a target
// STEER = DESIRED MINUS VELOCITY
Vehicle.prototype.arrive = function(target) {
  var desired = PVector.sub(target,this.position);  // A vector pointing from the location to the target
  var d = desired.mag();
  // Scale with arbitrary damping within 100 pixels
  if (d < 100) {
    var m = map(d,0,100,0,this.maxspeed);
    desired.setMag(m);
  } else {
    desired.setMag(this.maxspeed);
  }

  // Steering = Desired minus Velocity
  var steer = PVector.sub(desired,this.velocity);
  steer.limit(this.maxforce);  // Limit to maximum steering force
  this.applyForce(steer);
}
    
Vehicle.prototype.display = function() {
  // Draw a triangle rotated in the direction of velocity
  var theta = this.velocity.heading() + PI/2;
  fill(127);
  stroke(200);
  strokeWeight(1);
  pushMatrix();
  translate(this.position.x,this.position.y);
  rotate(theta);
  beginShape();
  vertex(0, -this.r*2);
  vertex(-this.r, this.r*2);
  vertex(this.r, this.r*2);
  endShape(CLOSE);
  popMatrix();
}



